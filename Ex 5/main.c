#include <stdio.h>

int read_range(int low, int high) {
    int selection = 0;
    do {
        printf("Enter a number between %d and %d: ", low, high);
        if (scanf("%d", &selection) != 1) {
            while (getchar() != '\n');
            printf("Invaild input\n");
        } else if (selection < low || selection > high) {
            while (getchar() != '\n');
            printf("Number not in range\n");
        } else {
            return selection;

        }
    } while (selection != 0);
}

int main() {
    printf("Let's play!\n");
    for(int i = 0; i < 3; i++) {
        printf("Roll a die and enter your result.\n");
        int number = read_range(1, 6);
        if (number == 6) {
            printf("I got %d. It is a tie!\n", number);
        } else {
            printf("I got %d. I win!\n", number + 1);
        }
    }
    printf("Better luck next time. Bye!");
}
