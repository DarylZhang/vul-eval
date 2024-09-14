#include <iostream>
#include <cstring>

class DummyProcessor {
public:
    void process(const char* data) {
        std::cout << "Processing: " << data << std::endl;
    }
};

class DataHandler {
public:
    void handleData(const char* input) {
        DummyProcessor processor;
        processor.process(input);

        char buffer[10];

        strcpy(buffer, input);

        std::cout << "Buffer content: " << buffer << std::endl;
    }
};

int main() {
    const char* userInput = "This input is too long for the buffer!";

    if (strlen(userInput) >= 10) {
        std::cout << "Error: Input too long for buffer!" << std::endl;
        return 1;
    }

    DataHandler handler;
    handler.handleData(userInput);

    return 0;
}