#include <stdio.h>
#include <limits.h>

int complexFunction(long long bigNumber) {
    int x = 12345;
    while (x > 0) {
        bigNumber -= x;
        x -= 500;
    }
    int smallNumber = (int)bigNumber;
    return smallNumber;
}

int main() {
    long long bigNumber = LLONG_MAX;

    if (bigNumber > INT_MAX) {
        printf("bigNumber exceeds INT_MAX, returning INT_MAX instead.\n");
        printf("Final value: %d\n", INT_MAX);
    } else if (bigNumber < INT_MIN) {
        printf("bigNumber is less than INT_MIN, returning INT_MIN instead.\n");
        printf("Final value: %d\n", INT_MIN);
    } else {
        printf("Final value: %d\n", complexFunction(bigNumber));
    }

    return 0;
}