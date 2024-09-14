#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void process_data(const char *input, char *output) {
    strcpy(output, input);
    for (int i = 0; i < strlen(output); i++) {
        output[i] = output[i] + 2;
    }
}

void handle_error(const char *error_message) {
    fprintf(stderr, "Error: %s\n", error_message);
}

void dummy_umask(const char *filename) {
    char processed_data[256];

    // CWE-276
    umask(0000);

    int fd = open(filename, O_CREAT | O_WRONLY, 0666);
    if (fd < 0) {
        handle_error("Unable to create file");
        return;
    }

    process_data("Sensitive information", processed_data);

    write(fd, processed_data, strlen(processed_data));
    close(fd);
}

int main() {
    dummy_umask("vulnerable_tempfile.txt");
    return 0;
}