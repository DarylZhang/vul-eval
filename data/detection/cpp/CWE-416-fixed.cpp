#include <iostream>
#include <cstdlib>

void dummyProcessing(int *data, int size) {
    for (int i = 0; i < size; ++i) {
        data[i] = rand() % 100;
    }
}


void processData(int *inputArray, int size, int **validPtr) {
    dummyProcessing(*validPtr, size);

    if (*validPtr != nullptr) {
        int value = (*validPtr)[0];
        std::cout << "Value: " << value << std::endl;
    } else {
        std::cout << "Pointer is invalid\n";
    }
}

int* allocateAndValidatePointer(int size) {
    int *ptr = new int[size];
    return ptr;
}

void freePointer(int **ptr) {
    delete[] *ptr;
    *ptr = nullptr;
}

int main() {
    int userInput[10];
    int userSize;
    int *validPtr;

    std::cout << "Enter the size of the array: ";
    std::cin >> userSize;

    for (int i = 0; i < userSize; ++i) {
        userInput[i] = i * 2;
    }

    validPtr = allocateAndValidatePointer(userSize);

    if (validPtr == nullptr) {
        std::cout << "Failed to allocate memory\n";
        return 1;
    }

    processData(userInput, userSize, &validPtr);

    freePointer(&validPtr);

    return 0;
}