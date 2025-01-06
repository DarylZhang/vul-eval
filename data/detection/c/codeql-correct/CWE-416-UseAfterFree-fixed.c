#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//CWE-416: 修复使用后释放，确保不再使用已释放的指针
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
    buffer = NULL; // 修复：将指针置为NULL，防止后续使用

    // 修复：仅在指针不为NULL时使用
    if (buffer != NULL) {
        process_data(buffer, strlen(buffer));
        printf("Processed: %s\n", buffer);
    } else {
        printf("Buffer has been freed and is no longer available.\n");
    }
}

int main() {
    char *buffer = (char *)malloc(100 * sizeof(char));
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }
    strcpy(buffer, "Sensitive Information");

    execute_logic(buffer);
    return 0;
}