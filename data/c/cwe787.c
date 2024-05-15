#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initialGreeting();
void processData(char *data);
void finalMessage();

void vulnerableFunction(char *inputData) {
    char buffer[50];

    for (int i = 0; inputData[i] && i < 100; i++) {
        buffer[i] = inputData[i]; // 故意写入超出buffer的范围
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <data>\n", argv[0]);
        return 1;
    }

    initialGreeting();

    processData(argv[1]);

    finalMessage();

    return 0;
}

void initialGreeting() {
    printf("Welcome to the Vulnerable Program!\n");
    printf("Please proceed with caution.\n");
}

void processData(char *data) {
    printf("Processing your data...\n");
    vulnerableFunction(data);
    printf("Data processed.\n");
}

void finalMessage() {
    printf("Thank you for using our program.\n");
    printf("Goodbye!\n");
}
