#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int authenticate_user(const char *user) {
    if (strcmp(user, "admin") == 0) {
        return 1;
    }
    return 0;
}

void print_system_info() {
    printf("System information: [Dummy Info]\n");
}

void insecure_setuid() {
    char *user = "regular_user";

    if (!authenticate_user(user)) {
        printf("User authentication failed.\n");
        return;
    }

    /// CWE-276
    if (setuid(0) == -1) {
        perror("Error setting user ID");
    }

    print_system_info();
}

int main() {
    insecure_setuid();
    return 0;
}