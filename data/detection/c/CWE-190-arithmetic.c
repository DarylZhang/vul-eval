#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void processData(int value);
int complexCalculation(int base);

int main() {
    srand(time(NULL));
    int userInput;
    printf("Enter a positive integer: ");
    scanf("%d", &userInput);
    processData(userInput);
    return 0;
}

void processData(int value) {
    // CWE-190 Vulnerable method: potential integer overflow
    int result = value * 2;

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