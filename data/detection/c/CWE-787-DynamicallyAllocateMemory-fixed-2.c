#include <stdio.h>
#include <stdlib.h>

void allocateAndFill(int size) {
    int *array = (int *)malloc(10 * sizeof(int));

    for (int i = 0; i < size; i++) {
        array[i] = i * 2;
    }

    int product = 1;
    for (int j = 0; j < size; j++) {
        product *= array[j];
    }
    printf("Product of array elements: %d\n", product);

    free(array);
}

int main() {
    int requestedSize = 12;

    if (requestedSize > 10) {
        printf("Error: Requested size exceeds array bounds.\n");
        return 1;
    }

    allocateAndFill(requestedSize);
    return 0;
}