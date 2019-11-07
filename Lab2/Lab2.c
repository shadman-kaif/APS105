#include <stdio.h>
#include <math.h>

int main()
{
    double P,r,c,t; /*Creates the decimals for the numerical values*/
    int N; /*Creates integer for number of months*/
    printf("Enter the purchase price of the item: "); /*Displays to the user to input the purchase price of the item*/
    scanf("%lf",&P);
    printf("Enter the interest rate per year as a percentage: "); /*Displays to the user to input the interest rate per year as a percent*/
    scanf("%lf",&r);
    printf("Enter the number of months for repayment: "); /*Displays to the user to input the number of months for repayment*/
    scanf("%d",&N);
    double r_d;
    r_d=(r/12)/100;
    c=(r_d*P)/(1-pow((1+r_d),-N)); /*Monthly payment formula*/
    t=c*N; /*Total cost formula*/
    printf("The monthly payment is : %0.2lf\n",c);
    printf("The total cost of the purchase is: %0.2lf\n",t);
    return 0;
}
