#include <stdio.h>
#include <stdlib.h>

void dummy_func3(double *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] * 2.5;
    }
}

void cleanup(double *ptr) {
    if (ptr) {
        free(ptr);
    }
}

void process_floating_data() {
    double *data = (double *)malloc(10 * sizeof(double));
    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    for (int i = 0; i < 10; i++) {
        data[i] = i + 0.5;
    }

    dummy_func3(data, 10);

    free(data);
    data = NULL; // 修复：将指针置为NULL，防止后续使用

    cleanup(data); // 现在传递NULL，不会进行free
}

int main() {
    process_floating_data();
    return 0;
}