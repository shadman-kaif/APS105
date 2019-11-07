/*File:Lab4.c
 *Author: Shadman Kaif
 *Date: February 4, 2019
 *Description: This program outputs the midpoint, left-end point and right-end point approximations given that the left bound inputted is more than 
 *equal to -10, the right bound inputted is less than equal to 10, the number of rectangles is less than equal to 0, and the left bound is less than 
 *equal to the right bound; otherwise printing "Invalid inputs..."
 */ 

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

//Initiate the bool comand, defining which conditions would result in an invalid input//
bool validateInput(double leftBound, double rightBound, int numRectangles) {
    if (leftBound <= -10 || rightBound >= 10 || numRectangles <= 0 || leftBound >= rightBound) {
        printf("Invalid inputs... \n");
        //If the user inputs 0 0 0, then terminating main will be displayed//
        if (leftBound == 0 || rightBound == 0 || numRectangles == 0) {
            printf("\nTerminating main!\n");
            //Exit the execution of the code if 0 0 0 is entered//
            exit(0);
        }
        return false;
    }
    //If the above conditions are not met, we return true and continue with the code//
    else {
    return true;
    }
} 

//Create the function in which the Riemann sums will give approximates for the left end point, right end point and mid point//
double evalFunc(double x){
    double y = 2*pow(x,2) - 7*x - 2;
    return y;
}

int main(void) {
	double leftBound, rightBound, stepSize, midPointEval, leftPointEval, rightPointEval;
    int numRectangles;
    
    printf("Enter the Left boundary: a, Right boundary: b, and No. of rectangles to use. \nTo exit enter 0 0 0\n");
    scanf("%lf%lf%d",&leftBound,&rightBound,&numRectangles);
    
    //If an invalid input is detected, the user will be prommpted to input the three inputs again//
    while (validateInput(leftBound, rightBound, numRectangles) == false) {
        printf("\nEnter the Left boundary: a, Right boundary: b, and No. of rectangles to use. \nTo exit enter 0 0 0\n");
        scanf("%lf%lf%d", &leftBound, &rightBound, &numRectangles);
    } 
    
    //Calculating the delta X step size//
    stepSize = (rightBound - leftBound) / numRectangles;
    
    double leftBound2 = leftBound;
    double leftBound3 = leftBound;
    
    //Printing the arbitrary statements//
    printf("With Step Size: %0.4lf \nThe approximate integral of the f(x) = 2(x^2)-7x-2 \n", stepSize);
    printf("Bound between %0.2lf and %0.2lf, using %d rectangles is as follows\n", leftBound, rightBound, numRectangles);
    
    //Calculating the midpoint sum//
    int midPointCounter = 1;
    while(midPointCounter <= numRectangles) {
        midPointEval = midPointEval + evalFunc(leftBound + (stepSize/2))*stepSize;
        midPointCounter += 1;
        leftBound += stepSize;
    }
    
    //Calculating the left-end point sum//
    int leftPointCounter = 1;
    while(leftPointCounter <= numRectangles) {
        leftPointEval = leftPointEval + evalFunc(leftBound2) * stepSize;
        leftPointCounter += 1;
        leftBound2 += stepSize;
    }
    
    //Calculating the right-end point sum//
    int rightPointCounter = 1;
    while(rightPointCounter <= numRectangles) {
        rightPointEval = rightPointEval + evalFunc(leftBound3 + stepSize) * stepSize;
        rightPointCounter += 1;
        leftBound3 += stepSize;
    }
    
    //Printing the final statements//
    printf("\nMid point evaluation approximate: %0.4lf\n", midPointEval);
    printf("Left point evaluation approximate: %0.4lf\n", leftPointEval);
    printf("Right point evaluation approximate: %0.4lf\n", rightPointEval);
    
	return 0;
}
