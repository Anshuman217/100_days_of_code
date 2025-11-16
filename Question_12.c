//Write a program to input an integer and check whether it is positive, negative or zero using nested if–else.

#include <stdio.h>

int main () {
    int a;
    //Take input from the user
    printf("Enter an integer: ");
    scanf("%d", &a);
    
    //Check if the input is positive, negative or zero
    if (a < 0) {
        printf("The integer is a negative number");
    }

    else if (a > 0)
    {
        printf("The integer is a positive number");
    }
    else {
        printf("The integer is equal to 0");
    }
    return 0;
}