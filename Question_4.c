//Write a program to calculate the area and circumference of a circle given its radius.

#include<stdio.h>

int main() {
    int radius;
    float pi = 3.1415926, area, circumference;

    printf("Enter the radius of the circle:");
    scanf("%d", &radius);

    area = pi * radius * radius;
    circumference = 2 * pi * radius;

    printf("Area of the circle of radius %d is %0.2f\n", radius, area);
    printf("Circumference of the circle of radius %d is %0.2f", radius, circumference);

    return 0;
}