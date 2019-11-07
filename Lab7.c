/*File: Lab7.c
 *Author: Shadman Kaif
 *Date: March, 2019
 *Description: This program runs a reversi game, showing the available moves for white and black; it also flips the board if the move is valid.
 *It prints out "invalid move" if the move is not valid.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initialBoard(char board[][26], int n);
void printBoard(char board[][26], int n);
void boardConfiguration (char board[][26], int n);
bool positionInBounds(int n, int row, int col);
bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol);
void checkLegalMovesAvailable(char board[][26], int n, char colour);
bool validMove(char board[][26], int n, char colour, char row, char col);
void flipBoard(char board[][26], int n, char row, char col, char colour);

//Function to print board
void initialBoard(char board[][26], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            board[i][j] = 'U';
        }
    }

    //Initializes the standard four pieces in the centre
    board[(n/2)-1][(n/2)-1] = 'W';
    board[n/2][n/2] = 'W';
    board[(n/2)-1][n/2] = 'B';
    board[n/2][(n/2)-1] = 'B';
}

//This is the print board function
void printBoard(char board[][26], int n){
    printf("  ");
    for(int i=0; i<n; i++){
        printf("%c", i+97);
    }
    printf("\n");

    for(int i=0; i<n; i++){
        printf("%c ", i+97);
        for(int j=0; j<n; j++){
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

//This is the configuration functions which appears once
void boardConfiguration (char board[][26], int n) {
    printf("Enter board configuration:");
    printf("\n");
    char colour, row, col;

    //Prints the desired colour on the desired square
    do{
        scanf(" %c%c%c", &colour, &row, &col);
        board[row-'a'][col-'a'] = colour;
    } while (colour!='!' && row!='!' && col!='!');
}

//This checks if row and column are valid
bool positionInBounds(int n, int row, int col){
    if(row >= 0 && col >= 0 && row < n && col < n) {
        return true;
    }
    else {
        return false;
    }
}

//Checks each of the 8 possibilities
bool checkLegalInDirection(char board[][26], int n, int row, int col,
char colour, int deltaRow, int deltaCol){
    int count=1;
    while((positionInBounds(n,row+(count*deltaRow),col+(count*deltaCol))) && (board[row+(count*deltaRow)][col+(count*deltaCol)]!=colour) && (board[row+(count*deltaRow)][col+(count*deltaCol)]!='U')){
        count++;
        if((positionInBounds(n,row+(count*deltaRow),col+(count*deltaCol))) && (board[row+(count*deltaRow)][col+(count*deltaCol)]==colour)){
            return true;
        }
    }
    return false;
}

//Checks legal moves
void checkLegalMovesAvailable(char board[][26], int n, char colour){
    bool ender = true;
    printf("Available moves for %c:\n", colour);
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            if(board[row][col] == 'U'){
                for(int deltaRow = -1; deltaRow <= 1; deltaRow++){
                    if (ender == false) {
                        ender = true;
                        break;
                    }
                    for(int deltaCol = -1; deltaCol <= 1; deltaCol++){
                        if(deltaRow == 0 && deltaCol == 0){
                        }
                        else if (checkLegalInDirection(board, n, row, col, colour, deltaRow, deltaCol)){
                            printf("%c%c\n", row+'a', col+'a');
                            ender = false;
                            break;
                        }
                    }
                }
            }
        }
    }
}

//Checks for valid move for the inputted move
bool validMove(char board[][26], int n, char colour, char row, char col){
    int integerRow = row - 'a';
    int integerCol = col - 'a';

    if(positionInBounds(n, integerRow, integerCol)){
        if(board[integerRow][integerCol] == 'U'){
            for(int deltaRow = -1; deltaRow <= 1; deltaRow++){
                for(int deltaCol = -1; deltaCol <= 1; deltaCol++){
                   if(deltaRow == 0 && deltaCol == 0){
                    }
                    else if (checkLegalInDirection(board, n, integerRow, integerCol, colour, deltaRow, deltaCol)){
                        printf("Valid move.\n");
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

//Flips the board if input is valid
void flipBoard(char board[][26], int n, char row, char col, char colour){
    int integerRow = row - 'a';
    int integerCol = col - 'a';

    for(int deltaRow = -1; deltaRow <= 1; deltaRow++){
        for(int deltaCol = -1; deltaCol <= 1; deltaCol++){
            if(deltaRow == 0 && deltaCol == 0){
            }
            else if (checkLegalInDirection(board, n, integerRow, integerCol, colour, deltaRow, deltaCol)){
                int count = 1;
                while(board[integerRow+(count*deltaRow)][integerCol+(count*deltaCol)] != colour){
                    board[integerRow+(count*deltaRow)][integerCol+(count*deltaCol)] = colour;
                    count++;
                }
            }
        }
    }
}

int main(void) {
    int n;
    char board[26][26];

    //Prompts user to enter the board dimension
    printf("Enter the board dimension: ");
    scanf("%d", &n);

    initialBoard(board, n);
    printBoard(board, n);
    boardConfiguration (board, n);
    printBoard(board, n);
    checkLegalMovesAvailable(board, n, 'W');
    checkLegalMovesAvailable(board, n, 'B');

    char colour, row, col;
    printf("Enter a move:\n");
    scanf("\n%c%c%c", &colour, &row, &col);

    if ((validMove(board, n, colour, row, col) == true)){
        board[row-'a'][col-'a'] = colour;
        flipBoard(board, n, row, col, colour);
        printBoard(board, n);
    }

    else if ((validMove(board, n, colour, row, col) == false)){
        printf("Invalid move.\n");
        printBoard(board, n);
    }

    return 0;
}