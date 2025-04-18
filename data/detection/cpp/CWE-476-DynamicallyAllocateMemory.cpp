#include <iostream>
#include <cstdlib>

void dummyFunc2(int *ptr) {
    *ptr += 1;
}

void processArray(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    std::cout << "Sum: " << sum << std::endl;
}

void riskyMemoryUsage(int* data, int size) {
    dummyFunc2(data);

    for (int i = 0; i < size; ++i) {
        data[i] = i * 2;
    }

    processArray(data, size);

    if (data[0] > 0) {
        std::cout << "Data array first element is positive" << std::endl;
    } else {
        std::cout << "Data array first element is non-positive" << std::endl;
    }
}

int main() {
    int *data = (int*)malloc(5 * sizeof(int));

    int dummyArray[5] = {1, 2, 3, 4, 5};
    riskyMemoryUsage(data, 5);
    riskyMemoryUsage(dummyArray, 5);

    free(data);

    return 0;
}