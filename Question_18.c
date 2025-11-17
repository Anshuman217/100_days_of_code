/*Write a program that accepts a percentage (0-100) and assigns a grade based on the following criteria: 
90-100: Grade A 
80-89: Grade B 
70-79: Grade C 
60-69: Grade D 
below 60: Grade F. */

#include <stdio.h>

int main () {
    int a;

    printf("Enter the percentage (0-100): ");
    scanf("%d", &a);

    if (a < 0 || a >100) {
        printf("Invalid input, please enter a integer between 0 to 100");
        return 1;
    }
        if (a >= 90 && a <=100) {
            printf("You have scored Grade A");
        }

        else if (a >=80 && a <= 89){
            printf("You have scored Grade B");
        }
    
        else if (a >= 70 && a <= 79) {
            printf("You have scored grade C");
        }
    
        else if (a >=60 && a <= 69) {
            printf("You have scored grade D");
        }
    
        else {
            printf("You have scored Grade F");
        }
    return 0;
}