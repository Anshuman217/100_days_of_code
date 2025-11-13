//Write a program to swap two numbers using a third variable.

#include <stdio.h>

int main() {
    int a, b, c;
    
    printf("Enter the first number: ");
    scanf("%d", &a);
    
    printf("Enter the second number: ");
    scanf("%d", &b);

    printf("Numbers before swapping: first number = %d and second number = %d\n", a, b);

    c = a;
    a = b;
    b = c;

    printf("Numbers after swapping: first number = %d and second number = %d", a, b);

    return 0;
}