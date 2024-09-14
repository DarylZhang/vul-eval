#include <iostream>

void dummyFunc1(int *val) {
    if (*val > 10) {
        *val += 5;
    } else {
        *val -= 3;
    }
}

int calculateSomething(int* arr, int size) {
    int total = 0;
    for (int i = 0; i < size; ++i) {
        total += arr[i];
    }
    return total;
}

void complexLogic(int* ptr, int size) {
    int dummyResult = calculateSomething(ptr, size);

    for (int i = 0; i < size; ++i) {
        dummyResult += ptr[i] * 2;
    }

    dummyFunc1(&dummyResult);

    // CWE-476: NULL pointer dereference
    if (*ptr > 0) {
        std::cout << "Pointer value is positive: " << *ptr << std::endl;
    } else {
        std::cout << "Pointer value is non-positive: " << *ptr << std::endl;
    }
}

int main() {
    int* data = nullptr;
    int dummyVar1 = 5, dummyVar2 = 10;
    int dummyArray[5] = {1, 2, 3, 4, 5};

    complexLogic(data, 5);
    complexLogic(dummyArray, 5);

    dummyFunc1(&dummyVar1);
    dummyFunc1(&dummyVar2);

    return 0;
}