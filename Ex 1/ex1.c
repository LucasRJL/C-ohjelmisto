#include "stdio.h"
int main(void) {
    int choice;
    double ticket_price, taxi_price, money;
    printf("Enter price of bus ticket:");
    scanf("%lf", &ticket_price);

    printf("Enter price of taxi: ");
    scanf("%lf", &taxi_price);

    printf("\nHow much money do you have: ");
    scanf("%lf", &money);

    while (money >= ticket_price || money >= taxi_price) {
        printf("Do you want to take\n");
        printf(" 1) Bus (%.2lf euros)\n", ticket_price);
        printf(" 2) Taxi (%.2lf euros)\n", taxi_price);
        printf("Enter your selection: \n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You chose Bus.\n");
            if (money >= ticket_price) {
                money -= ticket_price;
                printf("You have %.2lf euros left\n", money);
            } else {
                printf("You don't have enough money for a bus.\n");
                printf("You have %.2lf euros left\n", money);
            }
        } else if (choice == 2) {
            printf("You chose Taxi.\n");
            if (money >= taxi_price) {
                money -= taxi_price;
                printf("You have %.2lf euros left\n", money);
            } else {
                printf("You don't have enough money for Taxi.\n");
                printf("You have %.2lf euros left\n", money);
            }
        }
    }
    printf("You need to walk. Bye");
}