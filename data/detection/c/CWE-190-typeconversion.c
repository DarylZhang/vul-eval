#include <stdio.h>
#include <limits.h>

int complexFunction(long long bigNumber) {
    int x = 12345;
    while (x > 0) {
        bigNumber -= x;
        x -= 500;
    }
    // CWE-190: Integer overflow or truncation risk here
    int smallNumber = (int)bigNumber;
    return smallNumber;
}

int main() {
    long long bigNumber = LLONG_MAX;
    printf("Final value: %d\n", complexFunction(bigNumber));
    return 0;
}