//Write a program to input three numbers and find the largest among them using if–else.

#include <stdio.h>

int main() {
    int a, b, c;

    //Taking input from the user
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    printf("Enter the third number: ");
    scanf("%d", &c);

    //Finding the largest number
    if (a == b && b == c) {
        printf("All three numbers are same");
    }

    if (a > b && a > c) {
        printf("The largest number among %d, %d and %d is %d", a, b, c, a);
    }
    else if (b > a && b > c) {
        printf("The largest number among %d, %d and %d is %d", a, b, c, b);
    }

    else {
        printf("The largest number among %d, %d and %d is %d", a, b, c, c);
    }

    return 0;
}