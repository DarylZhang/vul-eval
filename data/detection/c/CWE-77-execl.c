#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void dummy_string_process(const char* str) {
    int len = strlen(str);
    printf("String length: %d\n", len);
}

void execute_command(const char* user_input) {
    //CWE-77
    execl("/bin/sh", "sh", "-c", user_input, NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    dummy_string_process(argv[1]);

    execute_command(argv[1]);
    return 0;
}