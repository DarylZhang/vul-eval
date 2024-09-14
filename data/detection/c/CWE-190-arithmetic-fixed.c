#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void processData(int value);
int complexCalculation(int base);
int safeMultiply(int a, int b);

int main() {
    srand(time(NULL));
    int userInput;
    printf("Enter a positive integer: ");
    scanf("%d", &userInput);
    processData(userInput);
    return 0;
}

void processData(int value) {

    int result = safeMultiply(value, 2);

    if (result == -1) {
        printf("Error: Integer overflow detected\n");
        return;
    }

    for (int i = 0; i < 100; i++) {
        if (i % 3 == 0) {
            result += rand() % 50;
        } else if (i % 7 == 0) {
            result -= rand() % 25;
        }
    }

    int finalValue = complexCalculation(result);
    printf("Processed value: %d\n", finalValue);
}

int complexCalculation(int base) {
    int temp = base;
    for (int i = 0; i < 1000; i++) {
        if (i % 2 == 0) {
            temp = (temp * 3) / 2;
        } else {
            temp = (temp + 7) * 4 / 3;
        }

        if (i % 10 == 0) {
            temp = temp ^ (rand() % 100);
        }
    }
    return temp;
}

int safeMultiply(int a, int b) {
    if (a > 0 && b > 0 && a > INT_MAX / b) {
        return -1;
    }
    if (a < 0 && b < 0 && a < INT_MAX / b) {
        return -1;
    }
    if (a > 0 && b < 0 && b < INT_MIN / a) {
        return -1;
    }
    if (a < 0 && b > 0 && a < INT_MIN / b) {
        return -1;
    }
    return a * b;
}