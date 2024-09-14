#include <stdio.h>
#include <stdlib.h>

void process_array(int *arr, int size) {
    int value = *(arr + size - 1);
    printf("Last value: %d\n", value);
}

int main() {
    int *array = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        array[i] = i * 2;  // 初始化数组
    }

    if (array != NULL && 5 > 0) {
        process_array(array, 5);
    } else {
        printf("Array size is invalid\n");
    }

    free(array);
    return 0;
}