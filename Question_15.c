//Write a program to input a character and check whether it is an uppercase alphabet, lowercase alphabet, digit, or special character.

#include <stdio.h>

int main () {
    char a;

    //Take the input from the user
    printf("Enter a character: ");
    scanf("%c", &a);

    //Check it's type
    if (a >= 'a' && a <= 'z') {
        printf("The character is a lowercase alphabet");
    }

    else if (a >= 'A' && a<= 'Z') {
        printf("The character is an Uppercase alphabet");
    }
    
    else if (a >= '0' && a <= '9') {
        printf("The character is a digit");
    }

    else {
        printf("The character is a special character");
    }
    
    return 0;
}