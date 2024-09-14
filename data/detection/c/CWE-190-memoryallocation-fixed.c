#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void processArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;
    }
}

int *allocateArray(int num) {

    if (num > 0 && num <= (INT_MAX / (int)sizeof(int))) {
        int size = num * sizeof(int);
        int *arr = (int *)malloc(size);
        if (arr) {
            processArray(arr, num);
        }
        return arr;
    } else {
        printf("Error: Integer overflow or invalid allocation size.\n");
        return NULL;
    }
}

int main() {
    int *array = allocateArray(1000000);
    if (array) {
        printf("Array allocated and processed.\n");
        free(array);
    }
    return 0;
}