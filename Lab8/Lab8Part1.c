/*File: Lab8.c
 *Author: Shadman Kaif
 *Date: March, 2019
 *Description: This program runs a reversi game, showing the available moves for white and black; it also flips the board if the move is valid.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initialBoard(char board[][26], int n);
void printBoard(char board[][26], int n);
bool positionInBounds(int n, int row, int col);
bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol);
bool validMove(char board[][26], int n, char colour);
bool checkValidMove(char board[][26], int n, char colour, char row, char col);
void flipBoard(char board[][26], int n, char row, char col, char colour);
void humanMoves (char board[][26], int n, char colour);
void computerMoves (char board[][26], int n, char colour);
int tilesFlipped(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol);
bool flipTiles(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol);
bool gameEnd(char board[][26], int n);
bool fullBoard(char board[][26], int n);
void winner(char board[][26], int n);

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
bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol){
    int count=1;
    while((positionInBounds(n,row+(count*deltaRow),col+(count*deltaCol))) && (board[row+(count*deltaRow)][col+(count*deltaCol)]!=colour) && (board[row+(count*deltaRow)][col+(count*deltaCol)]!='U')){
        count++;
        if((positionInBounds(n,row+(count*deltaRow),col+(count*deltaCol))) && (board[row+(count*deltaRow)][col+(count*deltaCol)]==colour)){
            return true;
        }
    }
    return false;
}

//Checks for valid move for the inputted move
bool validMove(char board[][26], int n, char colour){
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {
            for(int deltaRow = -1; deltaRow <= 1; deltaRow++){
                for(int deltaCol = -1; deltaCol <= 1; deltaCol++){
                   if(deltaRow == 0 && deltaCol == 0){
                    }
                    else if (checkLegalInDirection(board, n, row, colour, colour, deltaRow, deltaCol)){
                        return false;
                    }
                }
            }
        }
    }
    return true;
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

bool flipTiles(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol){
    int count=1;
    while((positionInBounds(n,row+(count*deltaRow),col+(count*deltaCol))) && (board[row+(count*deltaRow)][col+(count*deltaCol)]!=colour) && (board[row+(count*deltaRow)][col+(count*deltaCol)]!='U')){
        count++;
        if((positionInBounds(n,row+(count*deltaRow),col+(count*deltaCol))) && (board[row+(count*deltaRow)][col+(count*deltaCol)]==colour)){
            return count-1;
        }
    }
    return 0;
}

bool checkValidMove(char board[][26], int n, char colour, char row, char col){
    int integerRow = row - 'a';
    int integerCol = col - 'a';

    if(positionInBounds(n, integerRow, integerCol)){
        if(board[integerRow][integerCol] == 'U'){
            for(int deltaRow = -1; deltaRow <= 1; deltaRow++){
                for(int deltaCol = -1; deltaCol <= 1; deltaCol++){
                   if(deltaRow == 0 && deltaCol == 0){
                    }
                    else if (checkLegalInDirection(board, n, integerRow, integerCol, colour, deltaRow, deltaCol)){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void humanMoves (char board[][26], int n, char colour) {
    char row, col, otherPlayer;
    
    if (colour == 'B'){
        otherPlayer = 'W';
    }
    if (colour == 'W'){
        otherPlayer = 'B';
    }
    
    if (checkValidMove(board, n, colour, row, col)) {
        printf("%c player has no valid move.", colour);
        return;
    }
    
    printf("Enter move for colour %c (RowCol): ", colour);
    scanf(" %c%c", &row, &col);
    
    if (checkValidMove(board, n, colour, row, col)){
        board[row-'a'][col-'a'] = colour;
        flipBoard(board, n, row, col, colour);
        printBoard(board, n);
    }
    
    else {
        printf("Invalid move.\n");
        printf("%c player wins.\n", colour);
        exit(0);
    }
}

void computerMoves (char board[][26], int n, char colour) {
    int highestScore[] = {0, 0, 0};
    int numberTilesFlipped = 0;
    int row, col;
    
    if(validMove(board, n, colour)){
        printf("%c player has no valid move.", colour);
        return;
    }
    
     for(row=0; row<n; row++){
        for(col=0; col<n; col++){
            if(board[row][col] == 'U'){
                for(int deltaRow = -1; deltaRow <= 1; deltaRow++){
                    for(int deltaCol = -1; deltaCol <= 1; deltaCol++){
                        if(deltaRow == 0 && deltaCol == 0){
                        }
                        else if (checkLegalInDirection(board, n, row, col, colour, deltaRow, deltaCol)){
                            numberTilesFlipped = numberTilesFlipped + tilesFlipped;
                        }
                    }
                }
            }
        }
    }
    
    if (highestScore[2] < numberTilesFlipped){
        highestScore[0] = row;
        highestScore[1] = col;
        highestScore[2] = numberTilesFlipped;
    }
    
    printf("Computer places %c at %c%c.", colour, highestScore[0]+'a', highestScore[1]+'a');
    board[highestScore[0]][highestScore[1]] = colour;
    flipBoard(board, n, row, col, colour);
    printBoard(board, n);
}

int tilesFlipped(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol) {
    int count=1;
    while((positionInBounds(n,row+(count*deltaRow),col+(count*deltaCol))) && (board[row+(count*deltaRow)][col+(count*deltaCol)]!=colour) && (board[row+(count*deltaRow)][col+(count*deltaCol)]!='U')){
        count++;
        if((positionInBounds(n,row+(count*deltaRow),col+(count*deltaCol))) && (board[row+(count*deltaRow)][col+(count*deltaCol)]==colour)){
            return (count-1);
        }
    }
    return 0;
}

bool fullBoard(char board[][26], int n) {
    for (int row = 0; row < n; row++){
        for (int col = 0; col < n; col++) {
            if (board[row][col] == 'U') {
                return false;
            }
        }
    }
    return true;
}

bool gameEnd(char board[][26], int n) {
    if (validMove(board, n, 'W') && validMove(board, n, 'B')) {
        return true;
    }
    else if (fullBoard(board, n)){
        return true;
    }
    else {
        return false;
    }
}

void winner(char board[][26], int n){
    int whitePieces = 0, blackPieces = 0;
    for (int row = 0; row < n; row++){
        for (int col = 0; col < n; col++){
            if (board[row][col] == 'W'){
                whitePieces++;
            }
            if (board[row][col] == 'B'){
                blackPieces++;
            }
        }
    }
    if (blackPieces > whitePieces) {
        printf("B player wins.");
    }
    if (whitePieces > blackPieces) {
        printf("W player wins.");
    }
    else {
        printf("The game is a tie.\n");
    }
}

int main(void) {
    int n;
    char board[26][26];
    char player, playerOne, colour;
    int blackPieces, whitePieces;

    //Prompts user to enter the board dimension
    printf("Enter the board dimension: ");
    scanf("%d", &n);
    
    printf ("Computer plays (B/W): ");
    scanf(" %c", &player);
    
    if (player == 'B'){
        playerOne = 'W';
    }
    
    else if (player == 'W'){
        playerOne = 'B';
    }
    
    initialBoard(board, n);
    printBoard(board, n);
    
    while (gameEnd(board, n) == false) {
        if (player == 'B') {
            computerMoves(board, n, colour);
            if (gameEnd == true) {
                printf("%c player wins.\n", colour);
            }
        }
        else if (player == 'W') {
            humanMoves(board, n, colour);
            if (gameEnd == true) {
                printf("%c player wins.\n", colour);
            }
        }
    }
    
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (board[row][col] == 'B') {
                blackPieces++;
            }
            else if (board[row][col] == 'W') {
                whitePieces++;
            }
        }
    }
    
    winner(board, n);
    
    return 0;
}
