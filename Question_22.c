//Write a program to find profit or loss percentage given cost price and selling price.

#include <stdio.h>

int main () {
    float cp, sp, profit, profitpercent, losspercent, loss;

    printf("Enter the cost price: ");
    scanf("%f", &cp);
    printf("Enter the selling price: ");
    scanf("%f", &sp);

    if (cp <= 0) {
        printf("Cost price cannot be less than or equal to 0");
        return 0;
    }

        if (sp > cp) {
        profit = sp - cp;
        profitpercent = (profit * 100) / cp;
        printf("The profit percentage is %.2f percent", profitpercent);
        }

        else if (cp > sp) {
        loss = cp - sp;
        losspercent = (loss *100) / cp;
        printf("The loss percentage is %.2f percent", losspercent);
        }

        else {
            printf("No profit, no loss");
        }

    return 0;

}