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

        safeCopy(input);
    }

private:
    void safeCopy(const char* input) {
        char buffer[10];

        // Avoid CWE-119: Improper Restriction of Operations within the Bounds of a Memory Buffer
        if (strlen(input) < sizeof(buffer)) {
            strcpy(buffer, input);
            std::cout << "Buffer content: " << buffer << std::endl;
        } else {
            std::cout << "Input is too large for the buffer!" << std::endl;
        }
    }
};

int main() {
    const char* userInput = "This input is too long for the buffer!";
    DataHandler handler;
    handler.handleData(userInput);

    return 0;
}