#include <stdio.h>
#include <stdlib.h>

void allocateAndFill(int size) {
    int *array = (int *)malloc(10 * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    // 修复：限制 size 不超过数组大小
    if (size > 10) {
        printf("Requested size %d exceeds allocated array size. Limiting to 10.\n", size);
        size = 10;
    }

    for (int i = 0; i < size; i++) {
        array[i] = i * 2;
    }

    int product = 1;
    for (int j = 0; j < 10; j++) {
        product *= array[j];
    }
    printf("Product of array elements: %d\n", product);

    free(array);
}

void dummyFunctionC() {
    printf("Task C running.\n");
}

int main() {
    dummyFunctionC();
    allocateAndFill(12);
    return 0;
}