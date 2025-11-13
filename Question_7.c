//Write a program to swap two numbers without using a third variable.

#include <stdio.h>

int main() {
    int a, b;

    printf("Enter the first number: ");
    scanf("%d", &a);

    printf("Enter the second number: ");
    scanf("%d", &b);

    printf("Before swapping: first number = %d and second number = %d\n", a, b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("After swapping: first number = %d and second number = %d", a, b);

    return 0;
}