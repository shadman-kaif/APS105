/*File:Lab3.c
 *Author: Shadman Kaif
 *Date: January 24, 2019
 * Description: This program outputs: the the number of coffees the user can purchase this month, 
 *the number of additional coffees they can redeem via coupons,
 •the amount of money and coupons the user will have left over at the end of the month, and 
 •The average price the user spent on coffee. The user must input the amount of coupons needed to redeem a free coffee.
 *the amount of money they have to spend on coffee and the price of one cup of coffee.
 **/ 

#include <stdio.h>
#include <math.h>
int main(void)
{
    double priceCoffee, money, moneyLeftover, averageCost, newFreeCoffee;
    int coupons, coffeePurchases, freeCoffee, extraCoupons; 
    
    printf("How much does a coffee cost? \n");
    scanf("%lf",&priceCoffee);
    if (priceCoffee<=0.01) { //Displaying invalid input if the price of coffee is $0 or a negative value//
        printf("Invalid input. \n"); 
        return 0; //Returns it back without executing the rest of the code//
    }
    
    printf("How many coupons does it take to get a free coffee? \n");
    scanf("%d", &coupons);
    if (coupons<=1) { //Displaying invalid input if the number of coupons is less than equal to 1//
        printf("Invalid input. \n");
        return 0; //Returns it back without executing the rest of the code//
    }
    
    printf("How much money do you have to spend on coffee this month? \n");
    scanf("%lf", &money);
    if (money<0) { //Displaying invalid input if you have less than $0 to spend on coffee//
        printf("Invalid input. \n");
        return 0; //Returns it back without executing the rest of the code//
    }
    
    coffeePurchases=money/priceCoffee; //coffeePurhcases was assigned as an integer, therefore displaying the integer division of money/priceCoffee//
    printf("This month, you can purchase %d coffees at $%0.2lf each.\n", coffeePurchases, priceCoffee);
    if (coffeePurchases<coupons) { //If the number of coupons required to get a free coffee is greater than the number of coffee purchases, the user will not get any free coffees//
        printf("You will not be able to redeem any additional coffees from coupons this month.\n");
    }
    
    freeCoffee=coffeePurchases/coupons; //The number of free coffees is the coffee purchases divided by how many coffees it takes to get a free coffee//
    newFreeCoffee=freeCoffee/coupons;
    moneyLeftover=money-(coffeePurchases*priceCoffee); //The money leftover is the initial amount of money we have subtracted by the money we spend//
    
    int totalCoupons=coffeePurchases;
    int fC = 0;
    while (totalCoupons >= coupons){
     totalCoupons = totalCoupons-coupons;
     fC+=1;
     totalCoupons+=1;
 }
    if (newFreeCoffee <1)
        newFreeCoffee = 1;
    extraCoupons=newFreeCoffee;//The number of extra coupons is the sum of the remainder between the division of coffee purchases and coupons added to the integer division of coffee purchases and coupons// 
    if (freeCoffee>0) {
        printf("You will be able to redeem an additional %d coffee(s) from coupons.\n", fC);
    }
    printf("At the end of the month, you will have $%0.2lf and %d coupon(s) remaining.\n",moneyLeftover,totalCoupons);
    
    averageCost=(money-moneyLeftover)/(fC+coffeePurchases);//The average cost is the division between the amount of money spent on coffee and the amount of coffees received//
    if (coffeePurchases>=1) { //If you are able to purchase at least one coffee, then you will have an average cost greater than $0//
        printf("On average, you spent $%0.2lf on each cup of coffee this month.\n", averageCost);
    }
    else { //If you do not have enough money to purchase one coffee, then the average cost on each cup of coffee is $0//
        printf("On average, you spent $0 on each cup of coffee this month.\n");
    }
    return 0;
}