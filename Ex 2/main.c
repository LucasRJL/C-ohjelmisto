#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MONTHS 12

int main(void) {
    float taxRate, income_lim, over_income_tr, income, income_total, excess_income;
    float incomeMonth[MONTHS];
    float incomeMonthTaxed[MONTHS];


    printf("Enter tax rate: ");
    scanf("%f", &taxRate);

    printf("Enter income limit: ");
    scanf("%f", &income_lim);

    printf("Enter tax rate for income over the limit: ");
    scanf("%f", &over_income_tr);

    for (int i = 0; i < MONTHS; i++) {
        printf("Enter income for month %d:", i+1);
        scanf("%f", &income);
        incomeMonth[i] = income;
        income_total += income;
        if (income_total > income_lim) {
            excess_income = income_total - income_lim;
            if (income > excess_income) {
                incomeMonthTaxed[i] = excess_income * (over_income_tr / 100);
                incomeMonthTaxed[i] += (income - excess_income) * (taxRate / 100);
            } else {
                incomeMonthTaxed[i] = income * (over_income_tr / 100);
            }
        } else {
            incomeMonthTaxed[i] = income * (taxRate / 100);
        }
        incomeMonth[i] = income;
    }

    printf("%6s %10s %8s \n",  "month",  "income", "tax");
    for (int e = 0; e < MONTHS; e++) {
        printf("%6d  %9.2f  %7.2f\n", e + 1, incomeMonth[e], incomeMonthTaxed[e]);
    }

}