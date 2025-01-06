#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

void dummy_file_check(const char *filename) {
    printf("Checking file: %s\n", filename);
}

int change_file_permissions(const char *filename, int mode) {
    dummy_file_check(filename);

    if (mode <= 0) {
        printf("Invalid mode, no action taken.\n");
        return -1;
    }

    int fd = open(filename, O_RDONLY | O_NOFOLLOW);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    struct stat file_stat;
    if (fstat(fd, &file_stat) != 0) {
        perror("fstat");
        close(fd);
        return -1;
    }

    if (file_stat.st_uid != geteuid()) {
        printf("Error: Insufficient permissions to modify this file.\n");
        close(fd);
        return -1;
    }

    if (fchmod(fd, mode) != 0) {
        perror("fchmod");
        close(fd);
        return -1;
    }

    printf("Permissions for '%s' changed to %o successfully.\n", filename, mode);
    close(fd);
    return 0;
}

int main() {
    if (change_file_permissions("user_file.txt", 0644) == 0) {
        printf("File permissions changed successfully.\n");
    } else {
        printf("Failed to change file permissions.\n");
    }
    return 0;
}