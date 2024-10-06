#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include <string.h>

void dummy_check(int id) {
    if (id % 2 == 0) {
        printf("Even ID, continuing...\n");
    } else {
        printf("Odd ID, checking further...\n");
    }
}

int check_privileges(int user_id) {
    struct passwd *pw = getpwuid(user_id);
    if (pw == NULL) {
        printf("Invalid user ID!\n");
        return 0;
    }

    if (user_id == 0 || strcmp(pw->pw_name, "admin") == 0) {
        printf("User has privileges to elevate\n");
        return 1;
    }

    printf("User does not have privileges to elevate\n");
    return 0;
}

int elevate_privileges(int user_id) {
    dummy_check(user_id);

    if (check_privileges(user_id)) {
        if (setuid(1001) == 0) {
            printf("Privileges elevated to user 1001\n");
        } else {
            printf("Failed to elevate privileges\n");
        }
    } else {
        printf("No privileges to elevate\n");
    }

    return 0;
}

int main() {
    int user_id = getuid();
    printf("Current user ID: %d\n", user_id);
    elevate_privileges(user_id);
    printf("Operation complete\n");

    return 0;
}