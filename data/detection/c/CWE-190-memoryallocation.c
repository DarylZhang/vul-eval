#include <stdio.h>
#include <stdlib.h>

void processArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;
    }
}

int *allocateArray(int num) {
    // CWE-190: Integer overflow risk here
    int size = num * sizeof(int);
    int *arr = (int *)malloc(size);
    if (arr) {
        processArray(arr, num);
    }
    return arr;
}

int main() {
    int *array = allocateArray(1000000);
    if (array) {
        printf("Array allocated and processed.\n");
        free(array);
    }
    return 0;
}