#include <stdio.h>

int main() {
    int number;
    long long result = 1;

    printf("Enter a non-negative integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }

    for (int i = 1; i <= number; i++) {
        result *= i;
    }

    printf("Factorial of %d is: %lld\n", number, result);

    return 0;
}