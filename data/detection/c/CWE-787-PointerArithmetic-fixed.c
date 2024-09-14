#include <stdio.h>

void modifyArray(char *arr, int length) {
    char *ptr = arr;

    if (length > 10) {
        length = 10;
    }

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
    modifyArray(buffer, 15);
    printf("Buffer content: %s\n", buffer);
    return 0;
}