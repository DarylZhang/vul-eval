#include <stdio.h>

int bitShiftFunction(int a) {
    int result = 0;
    for (int i = 0; i < 5; i++) {
        // CWE-190: Potential integer overflow when shifting bits
        result |= (a << i);

        // Dummy logic to make the code more complex
        if (result & 1) {
            result += 10;
        } else {
            result -= 5;
        }

        // Additional dummy logic
        if (result % 3 == 0) {
            result *= 2;
        } else {
            result /= 2;
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