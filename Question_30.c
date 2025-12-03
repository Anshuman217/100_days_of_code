#include <stdio.h>

int main() {
    int n, reversed = 0, remainder;

    printf("Enter an integer to reverse: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int originalN = n;

    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    printf("Reversed number of %d is: %d\n", originalN, reversed);

    return 0;
}