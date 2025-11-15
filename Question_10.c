//Write a program to input time in seconds and convert it to hours:minutes:seconds format.

#include <stdio.h>

int main() {
    int seconds, remainder, remainder2, minutes, hours;

    printf("Enter the number of seconds: ");
    scanf("%d", &seconds);

    minutes = seconds / 60;
    remainder = seconds % 60;
     hours = minutes / 60;

    if (minutes >= 60) {
        remainder2 = minutes % 60;
        printf("The time in hours:minutes:seconds format is %d:%d:%d", hours, remainder2, remainder);
    }

    else
    printf("The time in hours:minutes:seconds format is %d:%d:%d", hours, remainder2, remainder);

    return 0;
}