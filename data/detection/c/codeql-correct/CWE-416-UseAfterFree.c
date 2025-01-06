#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//CWE-416: 使用后释放，释放后仍使用指针
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

    //CWE-416: 使用已释放的内存
    process_data(buffer, strlen(buffer));

    printf("Processed: %s\n", buffer);
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