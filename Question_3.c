//Write a program to calculate the area and perimeter of a rectangle given its length and breadth.

#include<stdio.h>

int main() {
    int length, breadth;
    int area, perimeter;

    printf("Enter the length of the rectangle: ");
    scanf("%d", &length);
    
    printf("Enter the breadth of the rectabgle: ");
    scanf("%d", &breadth);
    
    perimeter = 2 * (length + breadth);
    area = length * breadth;
    
    printf("The area and perimener of the rectangle is %d and %d respectively", area, perimeter);
    
    return 0;
}