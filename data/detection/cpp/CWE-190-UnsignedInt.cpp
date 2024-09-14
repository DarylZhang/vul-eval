#include <iostream>
#include <vector>

unsigned int calculateSomething(unsigned int x, unsigned int y) {
    unsigned int result = 1;
    for (unsigned int i = 0; i < y; ++i) {
        result *= (x + i);
    }
    return result;
}

void dummyLogic(std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        arr[i] *= i;
    }
}

unsigned int dummyModuloOperation(unsigned int x, unsigned int y) {
    return (x % y) + (y % x);
}

unsigned int unsignedAddOf(unsigned int largeValue, unsigned int increment) {
    // CWE-190: Unsigned integer overflow
    return largeValue + increment;
}

int main() {
    unsigned int largeValue = 4000000000;
    unsigned int increment = 1000000000;

    unsigned int result = unsignedAddOf(largeValue, increment);

    std::cout << "Result: " << result << std::endl;

    std::vector<int> dummyArr = {1, 2, 3, 4, 5};
    dummyLogic(dummyArr);
    dummyModuloOperation(largeValue, increment);

    return 0;
}