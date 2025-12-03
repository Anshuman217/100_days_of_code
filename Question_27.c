#include <stdio.h>

int main() {
    int n;
    int sum = 0;
    int i;

    printf("Enter the value of n (number of odd terms): ");

    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    if (n == 0) {
        printf("The sum of the first 0 odd numbers is 0.\n");
        return 0;
    }

    printf("The odd numbers being summed are: ");
    for (i = 1; i <= n; i++) {
        int odd_number = 2 * i - 1;

        printf("%d", odd_number);
        if (i < n) {
            printf(" + ");
        }

        sum += odd_number;
    }

    printf("\n\n");
    printf("The sum of the first %d odd numbers is: %d\n", n, sum);

    printf("(Confirmation using formula n*n: %d)\n", n * n);

    return 0;
}