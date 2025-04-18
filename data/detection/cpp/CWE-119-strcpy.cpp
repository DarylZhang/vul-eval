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
    DataHandler handler;
    handler.handleData(userInput);

    return 0;
}