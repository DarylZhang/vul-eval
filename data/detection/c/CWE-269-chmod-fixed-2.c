#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

void dummy_file_check(const char *filename) {
    printf("Checking file: %s\n", filename);
}

void change_file_permissions(const char *filename, int mode) {
    dummy_file_check(filename);

    if (chmod(filename, mode) == 0) {
        printf("Permissions for %s changed to %o\n", filename, mode);
    } else {
        printf("Failed to change permissions for %s\n", filename);
    }
}

int main() {
    const char *filename = "/etc/shadow";

    if (getuid() == 0) {
        change_file_permissions(filename, 0777);
    } else {
        printf("Insufficient privileges to change permissions for %s\n", filename);
    }

    return 0;
}