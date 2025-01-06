#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

void dummy_file_check(const char *filename) {
    printf("Checking file: %s\n", filename);
}

void change_file_permissions(const char *filename, int mode) {
    dummy_file_check(filename);

    if (mode > 0) {
        printf("Changing permissions for %s to %o\n", filename, mode);

        chmod(filename, mode);
    } else {
        printf("Invalid mode, no action taken.\n");
    }
}

int main() {
    const char *filename = "user_file.txt";

    // Check if the file is safe to modify
    struct stat file_stat;
    if (stat(filename, &file_stat) != 0) {
        perror("stat");
        printf("Error: File does not exist or cannot be accessed.\n");
        return -1;
    }

    if (file_stat.st_uid != geteuid()) {
        printf("Error: Insufficient permissions to modify this file.\n");
        return -1;
    }

    change_file_permissions(filename, 0644);
    printf("File permissions changed successfully.\n");

    return 0;
}