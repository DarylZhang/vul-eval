#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dummy_multiply(int a, int b) {
    return a * b;
}

void execute_command(const char* user_input) {
    FILE *fp = fopen("script.sh", "w");
    if (fp == NULL) {
        printf("Failed to create script\n");
        return;
    }

    fprintf(fp, "echo %s\n", user_input);
    fclose(fp);
    system("sh script.sh");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    if (strstr(argv[1], ";") != NULL || strstr(argv[1], "&") != NULL ||
        strstr(argv[1], "`") != NULL || strstr(argv[1], "$(") != NULL) {
        printf("Invalid input: potential command injection detected.\n");
        return 1;
    }

    int product = dummy_multiply(3, 5);
    printf("Dummy multiplication result: %d\n", product);

    execute_command(argv[1]);
    return 0;
}