#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

bool safeLeftShift(int a, int i, int *result);

int bitShiftFunction(int a) {
    int result = 0;
    for (int i = 0; i < 5; i++) {
        int shifted;
        // Fix CWE-190: Check for overflow before shifting
        if (!safeLeftShift(a, i, &shifted)) {
            printf("Error: Integer overflow detected during bit shifting.\n");
            return result;
        }
        result |= shifted;

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

bool safeLeftShift(int a, int i, int *result) {
    if (i < 0 || i >= (int)(sizeof(int) * 8)) {
        return false; // Shifting by negative or too large values is undefined
    }
    if (a > (INT_MAX >> i) || a < (INT_MIN >> i)) {
        return false; // Shifting would cause overflow
    }
    *result = a << i;
    return true;
}

int main() {
    int value = 1;
    int shiftedValue = bitShiftFunction(value);
    printf("Shifted result: %d\n", shiftedValue);
    return 0;
}