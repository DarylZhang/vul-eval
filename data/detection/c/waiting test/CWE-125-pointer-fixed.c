#include <stdio.h>
#include <stdlib.h>

void process_array(int *arr, int size) {

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i] % 2 == 0 ? i : -i;
    }
    printf("Dummy sum: %d\n", sum);

    // 修复 CWE-125 漏洞：添加边界检查
    if (size > 0 && size <= size) {
        int value = *(arr + size - 1);
        printf("Last element value: %d\n", value);
    } else {
        printf("Error: Invalid array size.\n");
    }
}

int main() {
    int *array = malloc(5 * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < 5; i++) {
        array[i] = i * 2;
    }
    process_array(array, 5);
    free(array);
    return 0;
}