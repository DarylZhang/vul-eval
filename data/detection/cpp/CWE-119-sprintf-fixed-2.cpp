#include <iostream>
#include <cstdio>

void log_message(const char* message) {
    std::cout << "Log: " << message << std::endl;
}

void perform_operation(int x) {
    for (int i = 0; i < x; ++i) {
        std::cout << "Operation step " << i << std::endl;
    }
}

void handle_message(char* msg) {
    std::cout << "Handling message: " << msg << std::endl;
    perform_operation(strlen(msg));
}

void log_data(int a, const char* data) {
    char log_msg[20];
    sprintf(log_msg, "Log: %s", data);
    log_message(log_msg);
    handle_message(log_msg);
}

void complex_analysis(int val) {
    for (int i = 0; i < val; ++i) {
        std::cout << "Analyzing step " << i << std::endl;
    }
}

int main() {
    char input_data[] = "ThisIsAVeryLongInput";

    if (strlen(input_data) >= 20) {
        std::cout << "Error: Input data too long for log." << std::endl;
        return 1;
    }

    complex_analysis(strlen(input_data));
    log_data(5, input_data);

    return 0;
}