#include <stdio.h>
#include <limits.h>

int bitShiftFunction(int a) {
    int result = 0;
    for (int i = 0; i < 5; i++) {

        if (a > 0 && a <= (INT_MAX >> i)) {
            result |= (a << i);
        } else {
            printf("Warning: Potential overflow detected in bit shift.\n");
            break;
        }

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
    int shiftedValue = bitShiftFunction(value);
    printf("Shifted result: %d\n", shiftedValue);
    return 0;
}