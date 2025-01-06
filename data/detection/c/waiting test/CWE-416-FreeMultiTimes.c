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
    for (int i = 0; i < 10; i++) {
        data[i] = i + 0.5;
    }

    dummy_func3(data, 10);

    free(data);

    //CWE-416: 使用后释放，重复释放同一指针
    cleanup(data);
}

int main() {
    process_floating_data();
    return 0;
}