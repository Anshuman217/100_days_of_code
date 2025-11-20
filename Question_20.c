//Write a program to display the day of the week based on a number (1–7) using switch-case.

#include <stdio.h>

int main() {
    int num;

    printf("Enter the day of the week based on a number (1-7): ");
    scanf("%d", &num);

    switch (num)
    {
    case 1:
        printf("First day of the week is Monday");
        break;

    case 2:
        printf("Second day of the week is Tuesday");
        break;

    case 3:
        printf("Third day of the week is Wednesday");
        break;

    case 4:
        printf("Fourth day of the week is Thursday");
        break;

    case 5:
        printf("Fifth day of the week is Friday");
        break;

    case 6:
        printf("Sixth day of the week is Saturday");
        break;

    case 7:
        printf("Seventh day of the week is Sunday");
        break;
    
    default:
        printf("Invalid input!");
        break;
    }

    return 0;
}