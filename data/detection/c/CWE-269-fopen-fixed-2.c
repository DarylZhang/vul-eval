#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

void dummy_log(const char *message) {
    printf("Log: %s\n", message);
}

void process_file(const char *filename) {
    FILE *file;
    dummy_log("Starting file processing");

    file = fopen(filename, "w");
    if (file != NULL) {
        fprintf(file, "Sensitive data modification.\n");
        fclose(file);
    } else {
        dummy_log("Failed to open the file");
    }

    dummy_log("File processing complete");
}

int main() {
    const char *filename = "/etc/passwd";

    if (access(filename, W_OK) == 0) {
        process_file(filename);
    } else {
        printf("Insufficient permissions to write to the file: %s\n", filename);
    }

    return 0;
}