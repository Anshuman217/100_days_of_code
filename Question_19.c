//Write a program to classify a triangle as Equilateral, Isosceles, or Scalene based on its side lengths.

#include <stdio.h>

int main () {
    float len1, len2, len3;

    printf("Enter the length of the first side of the triangle");
    scanf("%f", &len1);

    printf("Enter the length of the second side of the triangle");
    scanf("%f", &len2);

    printf("Enter the length of the third side of the triangle");
    scanf("%f", &len3);

    if (len1 < 0 || len2 < 0 || len3 < 0) {
        printf("Length cannot be negative, please enter a valid input.");
        return 1;
    }

        if ((len1 + len2 <= len3) || (len1 + len3 <= len2) || (len2 + len3 <= len1)) {
            printf("These lengths cannot form a triangle.");
            return 1;
        }

            if (len1 == len2 && len2 == len3) {
                printf("The triangle is an equilateral triangle");
            }

            else if (len1 == len2 || len2 == len3 || len3 == len1) {
                printf("The triangle is an isosceles triangle");
            }

            else {
                printf("The triangle is a scalene triangle");
            }
    
    return 0;
}