#include <stdio.h>
#include <sys/stat.h>

void dummy_file_check(const char *filename) {
    printf("Checking file: %s\n", filename);
}

void change_file_permissions(const char *filename, int mode) {
    dummy_file_check(filename);

    if (mode > 0) {
        printf("Changing permissions for %s to %o\n", filename, mode);

        // CWE-269: Changing file permissions without proper privilege checks
        chmod(filename, mode);
    } else {
        printf("Invalid mode, no action taken.\n");
    }
}

int main() {
    // Potentially dangerous: Modifying permissions of a sensitive file
    change_file_permissions("important_file.txt", 0777);
    return 0;
}