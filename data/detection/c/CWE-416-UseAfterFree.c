#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_data(char *data, int len) {
    for (int i = 0; i < len; i++) {
        data[i] = (char)(data[i] + 1);
    }
}

void dummy_func1(int *ptr) {
    *ptr = *ptr + 10;
}

void execute_logic(char *buffer) {
    dummy_func1((int *)buffer);

    free(buffer);

    // CWE-416
    process_data(buffer, strlen(buffer));

    printf("Processed: %s\n", buffer);
}

int main() {
    char *buffer = (char *)malloc(100 * sizeof(char));
    strcpy(buffer, "Sensitive Information");

    execute_logic(buffer);

    return 0;
}