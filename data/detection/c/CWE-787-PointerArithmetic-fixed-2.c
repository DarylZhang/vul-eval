#include <stdio.h>

void modifyArray(char *arr, int length) {
    char *ptr = arr;

    for (int i = 0; i < length; i++) {
        *ptr = 'X';
        ptr++;
    }

    for (int i = 0; i < length; i++) {
        if (arr[i] != 'X') {
            arr[i] = 'Z';
        }
    }
}

int main() {
    char buffer[10] = "hello";
    int inputLength = 15;

    if (inputLength > 10) {
        printf("Error: Length exceeds buffer size.\n");
        return 1;
    }

    modifyArray(buffer, inputLength);
    printf("Buffer content: %s\n", buffer);
    return 0;
}