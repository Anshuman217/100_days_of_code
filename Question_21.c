//Write a program to display the month name and number of days using switch-case for a given month number.

#include <stdio.h>

int main () {
    int monthno;

    printf("Enter the month number (1-12): ");
    scanf("%d", &monthno);

    switch (monthno)
    {
    case 1:
        printf("The first month of the year is January and it has 31 days");
        break;
        
    case 2:
        printf("The second month of the year is February and it has 28 days (29 on leap years)");
        break;
        
    case 3:
        printf("The third month of the year is March and it has 31 days");
        break;
        
    case 4:
        printf("The fourth month of the year is April and it has 30 days");
        break;
        
    case 5:
        printf("The fifth month of the year is May and it has 31 days");
        break;
        
    case 6:
        printf("The sixth month of the year is June and it has 30 days");
        break;
        
    case 7:
        printf("The seventh month of the year is July and it has 31 days");
        break;
            
    case 8:
        printf("The eighth month of the year is August and it has 31 days");
        break;
            
    case 9:
        printf("The ninth month of the year is September and it has 30 days");
        break; 

    case 10:
        printf("The tenth month of the year is October and it has 31 days");
        break; 

    case 11:
        printf("The eleventh month of the year is November and it has 30 days");
        break;

    case 12:
        printf("The twelfth month of the year is December and it has 31 days");
        break;
    
    default:
        printf("Invalid input!");
        break;
    }

    return 0;
}