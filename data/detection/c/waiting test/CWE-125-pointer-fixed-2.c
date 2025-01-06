#include <stdio.h>
#include <stdlib.h>

void process_array(int *arr, int size) {

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i] % 2 == 0 ? i : -i;
    }
    printf("Dummy sum: %d\n", sum);

    // CWE-125: 可能发生越界读取
    int value = *(arr + size);
    printf("Out of bounds value: %d\n", value);
}

int main() {
    int actual_size = 6; // 将数组大小增加1，避免越界
    int *array = malloc(actual_size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < actual_size; i++) {
        array[i] = i * 2;
    }
    process_array(array, 5);
    free(array);
    return 0;
}