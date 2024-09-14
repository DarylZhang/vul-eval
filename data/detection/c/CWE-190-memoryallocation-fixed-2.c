#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void processArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;
    }
}

int *allocateArray(int num) {
    int size = num * sizeof(int);
    int *arr = (int *)malloc(size);
    if (arr) {
        processArray(arr, num);
    }
    return arr;
}

int main() {
    int num = 1000000;

    if (num > 0 && num <= (INT_MAX / (int)sizeof(int))) {
        int *array = allocateArray(num);
        if (array) {
            printf("Array allocated and processed.\n");
            free(array);
        }
    } else {
        printf("Error: Integer overflow or invalid allocation size.\n");
    }

    return 0;
}