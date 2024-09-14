#include <stdio.h>
#include <stdlib.h>

void process_array(int *arr, int size) {

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i] % 2 == 0 ? i : -i;
    }
    printf("Dummy sum: %d\n", sum);

    if (size > 0) {
        int value = *(arr + size - 1);
        printf("Last value in bounds: %d\n", value);
    } else {
        printf("Array is empty\n");
    }
}

int main() {
    int *array = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        array[i] = i * 2;
    }
    process_array(array, 5);
    free(array);
    return 0;
}