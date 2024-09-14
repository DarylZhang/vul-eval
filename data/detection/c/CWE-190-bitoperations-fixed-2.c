#include <stdio.h>
#include <limits.h>

int bitShiftFunction(int a) {
    int result = 0;
    for (int i = 0; i < 5; i++) {
        result |= (a << i);
        if (result & 1) {
            result += 10;
        } else {
            result -= 5;
        }
    }
    return result;
}

int main() {
    int value = 1;

    if (value > 0 && value <= (INT_MAX >> 4)) {
        int shiftedValue = bitShiftFunction(value);
        printf("Shifted result: %d\n", shiftedValue);
    } else {
        printf("Error: Bit shift operation could cause overflow.\n");
    }

    return 0;
}