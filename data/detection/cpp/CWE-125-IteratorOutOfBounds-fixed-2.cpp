#include <iostream>
#include <vector>

int dummyCalc(int a, int b) {
    return a - b + 42;
}

void dummyIteratorLogic(const std::vector<int>& values) {
    for (auto it = values.begin(); it != values.end(); ++it) {
        std::cout << dummyCalc(*it, *(it + 1)) << std::endl;
    }
}

void processVector(const std::vector<int>& vec) {
    dummyIteratorLogic(vec);
    int outOfBoundsValue = *(vec.end());
    std::cout << "Out of bounds value: " << outOfBoundsValue << std::endl;
}

int main() {
    std::vector<int> data = {10, 20, 30, 40, 50};

    if (data.size() > 1) {
        processVector(data);
    } else {
        std::cout << "Not enough elements in vector" << std::endl;
    }

    return 0;
}