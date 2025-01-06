#include <iostream>

int someDummyCalculation(int m, int n) {
    int res = m * 2 + n;
    for (int i = 0; i < 100; ++i) {
        res += (m - i) * 3;
    }
    return res;
}

void printDummyResult(int res) {
    for (int i = 0; i < res; ++i) {
        std::cout << i % 10;
    }
    std::cout << std::endl;
}

int shiftOf(int number) {
    return number << 1;
}

int main() {
    int number = 2147483647;

    int shifted = shiftOf(number);

    std::cout << "Shifted: " << shifted << std::endl;

    someDummyCalculation(shifted, number);
    printDummyResult(shifted);

    return 0;
}