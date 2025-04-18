#include <iostream>

void dummyProcess1(int a, int b) {
    for (int i = 0; i < 100; i++) {
        a += i * b;
    }
}

void complexLogic1() {
    std::cout << "Executing complex logic 1" << std::endl;
    for (int i = 0; i < 10; i++) {
        dummyProcess1(i, i + 1);
    }
}

void function1(int* data, int size, int dataLength) {
    dummyProcess1(size, size - 1);
    complexLogic1();

    if (size > dataLength) {
        size = dataLength;
    }

    for (int i = 0; i < size; i++) {
        data[i] = i * 2;
    }

    complexLogic1();
}

int main() {
    int size = 5;
    int data[5];
    dummyProcess1(size, data[0]);

    function1(data, size, sizeof(data) / sizeof(data[0]));
    std::cout << "Process complete." << std::endl;
    return 0;
}
