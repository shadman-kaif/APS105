/*File: Lab1.c
 *Author: Shadman Kaif
 *Date: January 16, 2019
 *Description: This program calculates the product, difference and sum of the square roots of two positive integers 
 */ 

#include <stdio.h>
#include <math.h>

int main()
{
    double num1, num2, product, difference, sum;
	printf("Enter two positive integers: "); 
    scanf("%lf %lf",&num1,&num2);
    product=num1*num2;
    difference=num1-num2;
    sum=sqrt(num1)+sqrt(num2);
    printf("The product is: %0.2lf, the difference is: %0.2lf, the sum of roots is: %0.2lf\n", product, difference, sum);
	return 0;
}