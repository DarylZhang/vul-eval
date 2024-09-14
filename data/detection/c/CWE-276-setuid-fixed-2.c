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

void change_permissions() {
    if (setuid(0) == -1) {
        perror("Error changing user ID");
    }
    display_info();
}

int main() {
    char *current_user = "regular_user";

    if (validate_user(current_user)) {
        change_permissions();
    } else {
        printf("User %s does not have sufficient privileges.\n", current_user);
    }

    current_user = "admin";

    if (validate_user(current_user)) {
        change_permissions();
    } else {
        printf("User %s does not have sufficient privileges.\n", current_user);
    }

    return 0;
}