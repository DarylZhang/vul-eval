#include <stdio.h>
#include <stdlib.h>

void dummy_log(const char *message) {
    printf("Log: %s\n", message);
}

void process_file(const char *filename) {
    FILE *file;
    dummy_log("Starting file processing");

    //CWE-269
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
    process_file("/etc/passwd");
    return 0;
}