#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int input_validation(void) {
    int selection = 0;
    do {
        printf("Enter a number 1-3: ");
        if (scanf("%d", &selection) != 1) {
            while (getchar() != '\n');
            printf("Invaild input\n");
        } else if (selection < 1 || selection > 3) {
            while (getchar() != '\n');
            printf("Not a choice\n");
        } else {
            return selection;
        }
    } while (1);
}

int roll_d6(void) {
    srand(time(0));
    return 1+(rand() % 6);
}

int roll_d10(void) {
    srand(time(0));
    return 1+(rand() % 10);
}

int main() {
    int number;
    int validation;
    do {
        printf("\n1) Roll D6\n");
        printf("2) Roll D10\n");
        printf("3) Quit\n");
        validation = input_validation();
        switch (validation) {
            case 1:
                number = roll_d6();
                printf("You rolled a D6. Value is: %d\n", number);
                break;
            case 2:
                number = roll_d10();
                printf("You rolled a D10. Value is: %d\n", number);
                break;
            case 3:
                validation = 3;
            default:
                printf("Good bye :)\n");
        }
    } while (validation != 3);
}
