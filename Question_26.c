//Write a program to print numbers from 1 to n.

#include <stdio.h>

int main() {
    int a, i;

    printf("Type the number till where you would like to print the numbers: ");
    scanf("%d", &a);

    printf("The numbers from 1 to %d are: ", a);
    for (i = 1; i <= a; i++) 
    printf("%d\n", i);
    
    return 0;
}