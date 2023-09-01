#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INVALID_GRADE -1
#define STOP_INPUT 0
#define MIN_STUDENT_NUMBER 1
#define MIN_GRADE 0
#define MAX_GRADE 5

int main() {
    int std_amount, std_number, std_grade;

    printf("How many students?: ");
    scanf("%d", &std_amount);

    int grades[std_amount];

    for (int i = 0; i < std_amount; i++) {
        grades[i] = -1;
    }

    while (1) {
        printf("\nEnter student number (%d - %d) or %d to stop: ", MIN_STUDENT_NUMBER, std_amount, STOP_INPUT);
        scanf("%d", &std_number);
        if (std_number == STOP_INPUT) {
            break;
        }
        if (std_number >= MIN_STUDENT_NUMBER && std_number <= std_amount) {
            while (std_number != INVALID_GRADE) {
                printf("Enter grade (%d - %d) for student %d or %d to cancel: ", MIN_GRADE, MAX_GRADE, std_number, INVALID_GRADE);
                scanf("%d", &std_grade);

                if (std_grade == -1) {
                    break;
                } else if (std_grade >= MIN_GRADE && std_grade <= MAX_GRADE) {
                    grades[std_number - 1] = std_grade;
                    break;
                } else {
                    printf("Invalid grade!\n");
                }
            }
        } else {
            printf("Invalid student number!\n");
        }
    }
    printf("%-8s %5s\n", "Student", "Grade");

    for (int i = 0; i < std_amount; i++) {
        printf("%-8d ", i + 1);

        if (grades[i] == INVALID_GRADE) {
            printf("%-5s\n", "N/A");
        } else {
            printf("%-5d\n", grades[i]);
        }
    }

}