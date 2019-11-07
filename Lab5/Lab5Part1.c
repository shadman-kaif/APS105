/*File:Lab5Part1.c
 *Author: Shadman Kaif
 *Date: February 4, 2019
 *Description: 
 */ 
 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void input(int *num) {
    do {
        printf("Please enter an integer greater than 99999: ");
        scanf("%d", num);
        if (*num < 99999) {
            printf("Incorrect input.\n");
        }
    } while (*num <= 99999);
    printf("The number entered is %d\n", *num);
}

int add4(int num) {
    int i = 1;
    int addFourNum = 0;
    while (i <= num) {
        int adder = num / i;
        adder = adder + 4;
        adder = adder % 10;
        adder = adder * i;
        addFourNum = addFourNum + adder;
        i = i * 10;
    }
    return addFourNum;
}
 
int shift (int num) {
    int i = 1;
    int runShift = 0;
    while (i <= num) {
        int adder = num % (i*10);
        adder = adder / i;
        adder = adder * (i*10);
        runShift = runShift + adder;
        if ((runShift / 10) == num) {
            adder = num % (i*10);
            adder = adder / i;
            runShift = runShift + adder;
            runShift = runShift - (adder*(i*10)); 
        }
        i = i*10;
    }
    return runShift;
}

void printOutput(int encryptNum, int originalNum) {
    printf("Original number: %d\nEncrypted number: %d\n", originalNum, encryptNum);
}

int main (void) {
    int num, encryptNum, encrypt;
    input(&num);
    encrypt = add4(num);
    encryptNum = shift(encrypt);
    printOutput(encryptNum, num);
    return 0;
}
