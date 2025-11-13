//Write a program to find and display the sum of the first n natural numbers.

#include <stdio.h>

int main() {
    int n, i, sum = 0;
    
    printf("Enter the nth number till where you want to find the sum: ");
    scanf("%d", &n);

    if (n < 1) {
    printf("Please enter a valid input"); 
    return 1;
    }

    for ( i = n; i >= 1; i--) {
        sum += i;
    }
    printf("The sum of the first %d natural numbers is %d", n, sum);

    return 0;
}