#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void dummy_check(int id) {
    if (id % 2 == 0) {
        printf("Even ID, continuing...\n");
    } else {
        printf("Odd ID, checking further...\n");
    }
}

int elevate_privileges(int user_id) {
    dummy_check(user_id);

    if (user_id == 1001) {
        printf("Special user detected, granting root privileges\n");
        setuid(0);
    } else {
        printf("Normal user, no privileges granted\n");
    }

    return 0;
}

int main() {
    int user_id = getuid();
    printf("Current user ID: %d\n", user_id);

    if (user_id == 1001) {
        printf("User ID 1001 is not allowed to elevate privileges in this context\n");
    } else {
        elevate_privileges(user_id);
    }

    printf("Operation complete\n");

    return 0;
}