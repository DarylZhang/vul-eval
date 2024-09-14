#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_INPUT 256

void processUserInput(const char* input);
void performComplexOperation(int value);
int validateInput(const char* input);

int main() {
    char userInput[MAX_INPUT];
    printf("Enter a filename to process: ");
    fgets(userInput, sizeof(userInput), stdin);
    userInput[strcspn(userInput, "\n")] = 0;

    processUserInput(userInput);

    return 0;
}

void processUserInput(const char* input) {
    if (!validateInput(input)) {
        printf("Invalid input. Please enter only alphanumeric characters and underscores.\n");
        return;
    }

    char command[MAX_INPUT + 10];
    snprintf(command, sizeof(command), "ls -l %s", input);

    printf("Executing command: %s\n", command);
    system(command);

    srand(time(NULL));
    int randomValue = rand() % 100;
    performComplexOperation(randomValue);
}

void performComplexOperation(int value) {
    int result = value;
    for (int i = 0; i < 1000; i++) {
        if (i % 3 == 0) {
            result *= 2;
        } else if (i % 7 == 0) {
            result /= 3;
        } else {
            result += i;
        }

        if (result > 10000) {
            result %= 10000;
        }
    }
    printf("Complex operation result: %d\n", result);
}

int validateInput(const char* input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isalnum(input[i]) && input[i] != '_') {
            return 0;
        }
    }
    return 1;
}