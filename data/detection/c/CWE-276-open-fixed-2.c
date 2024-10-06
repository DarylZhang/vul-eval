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
    char *current_user = "regular_user";

    if (check_user_permissions(current_user)) {
        dummy_open("vulnerable_file.txt");
    } else {
        log_action("User does not have sufficient permissions to open file.");
    }

    current_user = "admin";

    if (check_user_permissions(current_user)) {
        dummy_open("vulnerable_file.txt");
    } else {
        log_action("User does not have sufficient permissions to open file.");
    }

    return 0;
}