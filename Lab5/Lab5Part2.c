#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int rollDice(void) {
    int diceOne, diceTwo, sum;
    diceOne = rand()%6 + 1;
    diceTwo = rand()%6 + 1;
    sum = diceOne + diceTwo;
    printf("You rolled: %d\n", sum);
    return sum;
}

bool playGame(void) {
    int sum;
    int point = 0;
    sum = rollDice();
    if (sum == 7 || sum == 11) {
        return true;
    }
    if (sum == 2 || sum == 3 || sum == 12) { 
        return false;
    }
    else {
        point = sum;
        printf("Your point is %d\n", point);
    }
    sum = rollDice();
    while (sum != point) {
        printf("You rolled: %d\n", sum);
        sum = rollDice();
        if (sum == point) {
            return true;
        }
        else if (sum == 7) {
            return false;
        }
    }
}

void winLoss (void) {
    int wins = 0;
    int losses = 0;
    char answer;
    bool game;
    do {
        game = playGame();
        if (game == true) {
            printf("You win!\n");
            wins++;
        }
        if (game == false) {
            printf("You lose!\n");
            losses++;
        }
        printf("Play again? ");
        scanf(" %c", &answer);
    } while (answer == 'Y' || answer == 'y');
    printf("Wins: %d\nLosses: %d\n", wins, losses);
}

int main (void) {
    winLoss();
    return 0;
}
