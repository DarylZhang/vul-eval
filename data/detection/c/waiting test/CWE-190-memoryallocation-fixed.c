#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

void processArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;
    }
}

bool safeMultiply(int a, int b, int *result) {
    if (a > 0 && b > 0 && a > INT_MAX / b) {
        return false; // 乘法溢出
    }
    *result = a * b;
    return true;
}

int *allocateArray(int num) {
    int size;
    // 修复 CWE-190：在乘法前检查是否会发生溢出
    if (!safeMultiply(num, sizeof(int), &size)) {
        printf("Error: Integer overflow detected during size calculation.\n");
        return NULL;
    }

    int *arr = (int *)malloc(size);
    if (arr) {
        processArray(arr, num);
    } else {
        printf("Error: Memory allocation failed.\n");
    }
    return arr;
}

int main() {
    int num = 1000000;
    int *array = allocateArray(num);
    if (array) {
        printf("Array allocated and processed.\n");
        free(array);
    } else {
        printf("Failed to allocate array.\n");
    }
    return 0;
}