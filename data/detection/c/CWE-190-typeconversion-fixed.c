#include <stdio.h>
#include <limits.h>

int complexFunction(long long bigNumber) {
    int x = 12345;
    while (x > 0) {
        bigNumber -= x;
        x -= 500;
    }

    if (bigNumber > INT_MAX) {
        printf("Overflow detected: Returning INT_MAX\n");
        return INT_MAX;
    } else if (bigNumber < INT_MIN) {
        printf("Underflow detected: Returning INT_MIN\n");
        return INT_MIN;
    }

    int smallNumber = (int)bigNumber;
    return smallNumber;
}

int main() {
    long long bigNumber = LLONG_MAX;
    printf("Final value: %d\n", complexFunction(bigNumber));
    return 0;
}