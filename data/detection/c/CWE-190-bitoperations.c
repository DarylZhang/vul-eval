#include <stdio.h>

int bitShiftFunction(int a) {
    int result = 0;
    for (int i = 0; i < 5; i++) {
        // CWE-190: Potential shift overflow here
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
    int shiftedValue = bitShiftFunction(value);
    printf("Shifted result: %d\n", shiftedValue);
    return 0;
}