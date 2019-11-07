/*File: Lab6.c
 *Author: Shadman Kaif
 *Date: February 18, 2019
 *Description: This program runs a simple tic-tac-toe game between two players 
 */ 

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

void printBoard(int board[], int playerA, int playerB);
int requestValidInput(int board[], int playerA, int playerB);
int checkForWinner(int board[], int playerA, int playerB);

void printBoard(int board[], int playerA, int playerB) {
    printf("\n");
    for (int i=0; i<9; i++) {
        if (board[i] < 64) {
            printf(" %d ", board[i]);
        }
        if (board[i] > 64) {
            printf(" %c ", board[i]);
        }
        if (i == 2) {
            printf("\n");
        }
        if (i == 5) {
            printf("\n");
        }
    }
    printf("\n\n");
}

int requestValidInput(int board[], int playerA, int playerB) {
    int nextMove;
    bool move = false;
    
    do { 
        scanf("%d", &nextMove);
        if (nextMove < 1 || nextMove > 9) {
            printf("Invalid input, please try again.\n");
            move = false;
        }
        else if (board[nextMove-1] == playerA || board[nextMove-1] == playerB) {
            printf("That position has already been played, please try again.\n");
            move = false;
        }
        else {
            move = true;
        }
    } while (move == false);
   
    return nextMove-1;
}

int checkForWinner(int board[], int playerA, int playerB) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == playerA && board[i+1] == playerA && board[i+2] == playerA) {
            return playerA;
        }
        else if (board[i] == playerB && board[i+1] == playerB && board[i+2] == playerB) {
            return playerB;
        }
        else if (board[i] == playerA && board[i+3] == playerA && board[i+6] == playerA) {
            return playerA;
        }
        else if (board[i] == playerB && board[i+3] == playerB && board[i+6] == playerB) {
            return playerB;
        }
        else if (board[i] == playerA && board[i+4] == playerA && board[i+8] == playerA) {
            return playerA;
        }
        else if (board[i] == playerB && board[i+4] == playerB && board[i+8] == playerB) {
            return playerB;
        }
        else if (board[i+2] == playerA && board[i+4] == playerA && board[i+6] == playerA) {
            return playerA;
        }
        else if (board[i+2] == playerB && board[i+4] == playerB && board[i+6] == playerB) {
            return playerB;
        }
        else if (board[i+3] == playerA && board[i+4] == playerA && board[i+5] == playerA) {
            return playerA;
        }
        else if (board[i+3] == playerB && board[i+4] == playerB && board[i+5] == playerB) {
            return playerB;
        }
        else if (board[i+6] == playerA && board[i+7] == playerA && board[i+8] == playerA) {
            return playerA;
        }
        else if (board[i+6] == playerB && board[i+7] == playerB && board[i+8] == playerB) {
            return playerB;
        }
        else if (board[i+1] == playerA && board[i+4] == playerA && board[i+7] == playerA) {
            return playerA;
        }
        else if (board[i+1] == playerB && board[i+4] == playerB && board[i+7] == playerB) {
            return playerB;
        }
        else if (board[i+2] == playerA && board[i+5] == playerA && board[i+8] == playerA) {
            return playerA;
        }
        else if (board[i+2] == playerB && board[i+5] == playerB && board[i+8] == playerB) {
            return playerB;
        }
        else {
            return 0;
        }
    }
}

int main(void)
{
    bool gameOver = false;
    int board[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int playerA = 65, playerB = 66;
    int currentPlayer = playerA;
    int input;
    int winner;
    int counter = 0;
    
    while (gameOver == false) {
        printf("The current state of the Tic-tac-toe Board:\n");
        printBoard(board, playerA, playerB);
        printf("It is Player %c's turn.\nPlease enter a valid position to play.\n", currentPlayer);
        //Updating game board
        input = requestValidInput(board, playerA, playerB);
        if (currentPlayer == playerA) {
            board[input] = 65;
            currentPlayer = playerB;
            counter = counter + 1;
        }
        else {
            board[input] = 66;
            currentPlayer = playerA;
            counter = counter + 1;
        }
        
        winner = checkForWinner(board, playerA, playerB);
        if (winner == playerA) {
            printf("Player A wins!\n");
            gameOver = true;
        }
        else if (winner == playerB) {
            printf("Player B wins!\n");
            gameOver = true;
        }
        
        //Checking for stalemate
        if (counter == 9 && winner != playerB && winner != playerA) {
            printf("It's a draw!\n");
            gameOver = true;
        }
    }
    
    //Printing the winner's name
    printBoard(board, playerA, playerB);
    return 0;
}