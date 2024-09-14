#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int check_user_permissions(const char *user) {
    if (strcmp(user, "admin") == 0) {
        return 1;
    }
    return 0;
}

void log_action(const char *action) {
    printf("[ACTION LOG]: %s\n", action);
}

void dummy_open(const char *filename) {
    log_action("Attempting to open file.");

    // CWE-276
    int fd = open(filename, O_CREAT | O_WRONLY, 0666);
    if (fd < 0) {
        perror("Error opening file");
        return;
    }

    const char *data = "Dummy content for vulnerable file.";
    write(fd, data, strlen(data));

    close(fd);
}

int main() {
    dummy_open("vulnerable_file.txt");
    return 0;
}