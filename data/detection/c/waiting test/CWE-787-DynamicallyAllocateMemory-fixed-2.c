#include <stdio.h>
#include <stdlib.h>

void allocateAndFill(int size) {
    int *array = (int *)malloc(10 * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    // 这里假设 size 已被调用者正确限制
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
    int requestedSize = 12;
    int maxSize = 10;

    if (requestedSize > maxSize) {
        printf("Requested size %d exceeds maximum allowed size %d. Limiting to %d.\n", requestedSize, maxSize, maxSize);
        requestedSize = maxSize;
    }

    allocateAndFill(requestedSize);

    return 0;
}