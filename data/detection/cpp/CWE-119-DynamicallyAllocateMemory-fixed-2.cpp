#include <iostream>
#include <cstring>

void log_action(const char* action, int value) {
    std::cout << "Logging action: " << action << " with value: " << value << std::endl;
}

void dummy_processing(const char* data, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        std::cout << "Dummy processing: " << i << " with data: " << data[i % strlen(data)] << std::endl;
    }
}

void advanced_calculation(int a, int b) {
    for (int i = 0; i < a; ++i) {
        std::cout << "Calculating... " << i << std::endl;
    }
    std::cout << "Final result: " << a * b << std::endl;
}

void process_data(int val, char* input) {
    dummy_processing(input, val);

    char log_msg[20];
    snprintf(log_msg, sizeof(log_msg), "Processing %d items", val);
    log_action(log_msg, val);

    advanced_calculation(val, strlen(input));
}

void copy_buffer(char* data) {
    int len = strlen(data);
    char* buffer = new char[len];

    memcpy(buffer, data, len);

    process_data(len, buffer);

    delete[] buffer;
}

int main() {
    char data[] = "SomeVeryLongInput";

    if (strlen(data) > 100) {
        std::cout << "Error: Input data too long" << std::endl;
        return 1;
    }

    copy_buffer(data);
    return 0;
}