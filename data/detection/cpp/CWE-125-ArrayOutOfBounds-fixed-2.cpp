#include <iostream>
#include <vector>
#include <string>

int dummyFunc1(int a, int b) {
    return a + b * 3;
}

std::string dummyFunc2(const std::string& s) {
    return s + "dummy";
}

void complexLogic() {
    int x = 5;
    for (int i = 0; i < x; ++i) {
        std::cout << dummyFunc2(std::to_string(dummyFunc1(i, x))) << std::endl;
    }
}

int findElement(const std::vector<int>& arr, int index) {
    complexLogic();
    int value = arr[index];
    return value;
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    int index = 6;

    if (index >= 0 && index < data.size()) {
        int result = findElement(data, index);
        std::cout << "Result: " << result << std::endl;
    } else {
        std::cout << "Index out of bounds" << std::endl;
    }

    return 0;
}