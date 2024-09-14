#include <iostream>
#include <cstdlib>

void dummyProcessing(int *data, int size) {
    for (int i = 0; i < size; ++i) {
        data[i] = rand() % 100;
    }
}


void processData(int *inputArray, int size) {
    int *tempArray = new int[size];
    dummyProcessing(tempArray, size);

    delete[] tempArray;

    // CWE-416 vulnerability: Use after free
    int value = tempArray[0];

    std::cout << "Value: " << value << std::endl;
}

int main() {
    int userInput[10];
    int userSize;

    std::cout << "Enter the size of the array: ";
    std::cin >> userSize;

    for (int i = 0; i < userSize; ++i) {
        userInput[i] = i * 2;
    }

    processData(userInput, userSize);

    return 0;
}