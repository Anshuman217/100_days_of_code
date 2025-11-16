//Write a program to input a character and check whether it is a vowel or consonant using if–else.

#include <stdio.h>

int main () {
    char a;

    //Inpur the character from the user
    printf("Enter a character: ");
    scanf("%c", &a);

    //Check if the input is valid or not
    if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
    
        if ((a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') || (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')) {
            printf("The character is a vowel");
        }
        else {
            printf("The character is a consonant");
        }
    
    else {
        printf("Please enter a valid input");
    }
    return 0;
}