#include <stdio.h>
#include <limits.h>

int complexFunction(long long bigNumber);

int main() {
    long long bigNumber = LLONG_MAX;

    // Fix CWE-190: Ensure bigNumber can be safely processed
    if (bigNumber > INT_MAX || bigNumber < INT_MIN) {
        printf("Error: Input value is too large and may cause integer overflow.\n");
        return 1;
    }

    printf("Final value: %d\n", complexFunction(bigNumber));
    return 0;
}

int complexFunction(long long bigNumber) {
    int x = 12345;
    while (x > 0) {
        bigNumber -= x;
        x -= 500;
    }

    // CWE-190: Potential integer overflow when casting bigNumber to int
    int smallNumber = (int)bigNumber;
    return smallNumber;
}