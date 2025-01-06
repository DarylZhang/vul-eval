#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <time.h>

#define MAX_INPUT 256

void processUserInput(const char* input);
void performComplexOperation(int value);

int main() {
    char userInput[MAX_INPUT];
    printf("Enter a filename to process: ");
    fgets(userInput, sizeof(userInput), stdin);
    userInput[strcspn(userInput, "\n")] = 0;

    processUserInput(userInput);
    return 0;
}

void processUserInput(const char* input) {
    // 白名单验证
    const char* allowed_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789._-/";
    size_t input_length = strlen(input);
    for (size_t i = 0; i < input_length; i++) {
        if (strchr(allowed_chars, input[i]) == NULL) {
            printf("Error: Invalid character detected in filename.\n");
            return;
        }
    }

    // 使用标准 C 库列出目录内容，避免使用 system 调用
    DIR* dir = opendir(input);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);

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