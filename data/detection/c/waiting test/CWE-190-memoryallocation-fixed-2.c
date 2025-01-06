#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void processArray(int *arr, int size);

int *allocateArray(int num) {
    // CWE-190: 计算 size 时可能发生整数溢出
    int size = num * sizeof(int);
    int *arr = (int *)malloc(size);
    if (arr) {
        processArray(arr, num);
    }
    return arr;
}

int main() {
    int num = 1000000;
    // 修复 CWE-190：在调用 allocateArray 前检查整数溢出
    if (num > 0 && num <= INT_MAX / (int)sizeof(int)) {
        int *array = allocateArray(num);
        if (array) {
            printf("Array allocated and processed.\n");
            free(array);
        } else {
            printf("Failed to allocate array.\n");
        }
    } else {
        printf("Error: Integer overflow detected in size calculation.\n");
    }
    return 0;
}

void processArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;
    }
}