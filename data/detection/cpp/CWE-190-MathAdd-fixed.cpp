#include <iostream>
#include <limits>

int complexFunction(int a, int b) {
    int temp = (a * b) + (a - b);
    for (int i = 0; i < 10; ++i) {
        temp += (a + i * b);
    }
    return temp;
}

int dummyOperation(int x, int y) {
    if (x < y) return complexFunction(x, y);
    return complexFunction(y, x);
}

int anotherDummyFunction(int x) {
    int result = 0;
    for (int i = 0; i < x; ++i) {
        result += i * i;
    }
    return result;
}

int add(int x, int y) {
    if (x > 0 && y > std::numeric_limits<int>::max() - x) {
        std::cerr << "Overflow detected!" << std::endl;
        return -1;
    }
    return x + y;
}

int main() {
    int x = 2147483640;
    int y = 20;

    int sum = add(x, y);

    std::cout << "Sum: " << sum << std::endl;

    dummyOperation(x, y);
    anotherDummyFunction(x);
    return 0;
}