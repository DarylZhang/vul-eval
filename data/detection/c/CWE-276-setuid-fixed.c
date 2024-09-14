#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int validate_user(const char *user) {
    if (strcmp(user, "admin") == 0) {
        return 1;
    }
    return 0;
}

void display_info() {
    printf("System information: [Dummy Info]\n");
}

void adjust_permissions(const char *user) {
    if (!validate_user(user)) {
        printf("User authentication failed.\n");
        return;
    }

    if (getuid() != 0) {
        printf("Operation requires root privileges.\n");
        return;
    }

    if (setuid(getuid()) == -1) {
        perror("Error adjusting user ID");
    }

    display_info();
}

int main() {
    char *current_user = "regular_user";
    adjust_permissions(current_user);

    current_user = "admin";
    adjust_permissions(current_user);

    return 0;
}