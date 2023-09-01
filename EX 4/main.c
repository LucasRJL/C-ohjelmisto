#include <stdio.h>

int read_integer(void) {
    int selection = 0;
    do {
        printf("Enter positive numbers or negative to stop: ");
        if(scanf("%d", &selection) != 1) {
            while(getchar() != '\n');
            printf("invalid input\n");
        } else {
            return selection;
        }
    } while(selection == 0);
}

int main() {
    int number, e = 0;
    float mean = 0;
    do {
        number = read_integer();
        if (number >= 0) {
            mean += number;
            e++;
        }
    } while (number >= 0);
    mean = mean/e;
    printf("You entered %d positive numbers. The average is: %.3f", e, mean);
}
