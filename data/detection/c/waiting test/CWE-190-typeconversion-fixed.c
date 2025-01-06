#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

bool safeCastToInt(long long value, int *result);

int complexFunction(long long bigNumber) {
    int x = 12345;
    while (x > 0) {
        bigNumber -= x;
        x -= 500;
    }

    int smallNumber;
    // Fix CWE-190: Check for overflow before casting
    if (!safeCastToInt(bigNumber, &smallNumber)) {
        printf("Error: Integer overflow detected during casting.\n");
        return 0; // Return an error code or handle appropriately
    }

    return smallNumber;
}

bool safeCastToInt(long long value, int *result) {
    if (value > INT_MAX || value < INT_MIN) {
        // Overflow would occur
        return false;
    }
    *result = (int)value;
    return true;
}

int main() {
    long long bigNumber = LLONG_MAX;
    printf("Final value: %d\n", complexFunction(bigNumber));
    return 0;
}