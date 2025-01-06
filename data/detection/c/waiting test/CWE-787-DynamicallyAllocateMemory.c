#include <stdio.h>
#include <stdlib.h>

void allocateAndFill(int size) {
    int *array = (int *)malloc(10 * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    // CWE-787: 当 size > 10 时，导致数组越界
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