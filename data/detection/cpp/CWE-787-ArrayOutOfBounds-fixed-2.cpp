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

void function2(int* data, int size) {
    dummyProcess1(size, size - 1);
    complexLogic1();

    for (int i = 0; i < size; i++) {
        data[i] = i * 2;
    }

    complexLogic1();
}

int main() {
    int size = 5;
    int* data = new int[size];
    dummyProcess1(size, data[0]);

    function2(data, size);
    std::cout << "Process complete." << std::endl;

    delete[] data;
    return 0;
}