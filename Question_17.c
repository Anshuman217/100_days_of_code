//Write a program to find the roots of a quadratic equation and categorize them.

#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    float x1, x2;
    double determinant;
    
    printf("Enter the coefficient of x^2: ");
    scanf("%d", &a);
    printf("Enter the coefficient of x: ");
    scanf("%d", &b);
    printf("Enter the constant term of the quadratic equation: ");
    scanf("%d", &c);

    if (a == 0) {
        printf ("The value of a cannot be 0, please enter a valid value of a");
        return 1;
    }

    determinant = (b * b) - (4 * a * c);

    if (determinant < 0) {
        printf("The equation has two complex roots");
        return 1;
    }

    x1 = (-b + sqrt(determinant)) / (2.0 * a);
    x2 = (-b - sqrt(determinant)) / (2.0 * a);

    printf("The roots of the quadratic equation %dx^2 + %dx + %d = 0 are %.2f and %.2f\n", a, b, c, x1, x2);

    if (determinant > 0) {
        printf("The equation has two distinct and real roots");
    }

    else if (determinant == 0) {
        printf("The equation has two same and real roots");
    }

    return 0;
}