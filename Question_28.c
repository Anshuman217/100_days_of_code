#include <stdio.h>

int main() {
    int n;
    long long product = 1;
    int i;

    printf("Enter the value of n (the upper limit): ");

    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    if (n < 2) {
        printf("The product of even numbers from 1 to %d is 1.\n", n);
        return 0;
    }

    printf("The even numbers being multiplied are: ");

    for (i = 2; i <= n; i += 2) {

        printf("%d", i);

        if (i + 2 <= n) {
            printf(" * ");
        }

        product *= i;
    }

    printf("\n\n");
    printf("The product of even numbers from 1 to %d is: %lld\n", n, product);

    return 0;
}