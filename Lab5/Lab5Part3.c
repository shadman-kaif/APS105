#include <stdio.h>
#include <math.h>

void inputDate(int *day, int *month, int *year) {
    printf("Please enter a date: ");
    scanf("%d/%d/%d", day, month, year);
}

void calculateDay(int day, int month, int year) {
    int a, b, c, d, w, x, y, z, r;
    a = month - 2;
    b = day;
    c = year % 100;
    d = year / 100;
    if(a == 0) {
        a = 12;
        c--;
    }
    if (a == -1) {
        a = 11;
        c--;
    }
    if (c<0) {
        c=c+100;
        d=d-1;
    }
    w = (13*a-1)/5;
    x = c/4;
    y = d/4;
    z = w + x + y + b + c - 2*d; 
    r = z % 7;
    if (r<0) {
        r = r + 7;
    }
    switch(r) {
        case 0 : printf("The day %d/%d/%d is a Sunday.\n", day, month, year); break;
        case 1 : printf("The day %d/%d/%d is a Monday.\n", day, month, year); break;
        case 2 : printf("The day %d/%d/%d is a Tuesday.\n", day, month, year); break;
        case 3 : printf("The day %d/%d/%d is a Wednesday.\n", day, month, year); break;
        case 4 : printf("The day %d/%d/%d is a Thurday.\n", day, month, year); break;
        case 5 : printf("The day %d/%d/%d is a Friday.\n", day, month, year); break;
        case 6 : printf("The day %d/%d/%d is a Saturday.\n", day, month, year); break;
    }
}
int main (void) {
    int day, month, year;
    inputDate(&day, &month, &year);
    calculateDay(day, month, year);
    return 0; 
}
