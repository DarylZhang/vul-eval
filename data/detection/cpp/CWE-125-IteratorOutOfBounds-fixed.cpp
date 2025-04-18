#include <iostream>
#include <vector>

int dummyCalc(int a, int b) {
    return a - b + 42;
}

void dummyIteratorLogic(const std::vector<int>& values) {
    for (auto it = values.begin(); it != values.end(); ++it) {
        if ((it + 1) != values.end()) {
            std::cout << dummyCalc(*it, *(it + 1)) << std::endl;
        }
    }
}

void processVector(const std::vector<int>& vec) {
    dummyIteratorLogic(vec);
    if (!vec.empty()) {
        int outOfBoundsValue = vec.back();
        std::cout << "Last value: " << outOfBoundsValue << std::endl;
    }
}

int main() {
    std::vector<int> data = {10, 20, 30, 40, 50};
    processVector(data);
    return 0;
}