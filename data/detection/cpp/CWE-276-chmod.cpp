#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <sys/stat.h>
#include <ctime>

class DataProcessor {
private:
    std::vector<int> data;

    void generateRandomData(int size) {
        srand(time(nullptr));
        for (int i = 0; i < size; ++i) {
            data.push_back(rand() % 1000);
        }
    }

    double complexCalculation() {
        double result = 0.0;
        for (size_t i = 0; i < data.size(); ++i) {
            result += std::sqrt(data[i]) + std::pow(2, i % 5);
            if (i % 10 == 0) {
                std::cout << "Intermediate result: " << result << std::endl;
            }
        }
        return result;
    }

public:
    void processAndSaveData(const std::string& filename) {
        generateRandomData(1000);

        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file" << std::endl;
            return;
        }

        // CWE-276 Vulnerability: Incorrect default permissions
        chmod(filename.c_str(), 0666);

        file << "Sensitive information: XYZ123" << std::endl;

        for (int num : data) {
            file << "Data point: " << num << std::endl;
        }

        double result = complexCalculation();
        file << "Final calculation result: " << result << std::endl;

        file.close();
    }
};

int main() {
    DataProcessor processor;
    processor.processAndSaveData("output.txt");
    return 0;
}