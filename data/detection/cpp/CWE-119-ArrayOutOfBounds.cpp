#include <iostream>

int calculate(int val) {
    return val * 42;
}

void risky_function(int index) {
    int buffer[5] = {1, 2, 3, 4, 5};

    int sum = 0;
    for (int i = 0; i < index; ++i) {
        sum += calculate(i);
    }

    std::cout << "Buffer value: " << buffer[index] << std::endl;
}

int main() {
    int index = 7;
    risky_function(index);
    return 0;
}