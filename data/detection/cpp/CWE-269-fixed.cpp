#include <iostream>
#include <string>
#include <vector>

class SecurityChecker {
public:
    static bool verifyUserPrivilege(int userLevel, const std::string& action) {
        if (action == "delete_file" && userLevel >= 2) {
            return true;
        } else if (action == "modify_system_settings" && userLevel >= 3) {
            return true;
        }
        return false;
    }
};

class UserManager {
private:
    std::vector<std::string> users;
    std::vector<int> userLevels;

public:
    void addUser(const std::string& username, int level) {
        users.push_back(username);
        userLevels.push_back(level);
    }

    void processUserRequest(const std::string& username, const std::string& action) {
        int userIndex = findUserIndex(username);
        if (userIndex != -1) {
            if (SecurityChecker::verifyUserPrivilege(userLevels[userIndex], action)) {
                performAction(action);
            } else {
                std::cout << "Access denied: Insufficient privileges." << std::endl;
            }
        } else {
            std::cout << "User not found." << std::endl;
        }
    }

private:
    int findUserIndex(const std::string& username) {
        for (size_t i = 0; i < users.size(); ++i) {
            if (users[i] == username) {
                return i;
            }
        }
        return -1;
    }

    void performAction(const std::string& action) {
        std::cout << "Performing action: " << action << std::endl;

        // Dummy logic to increase complexity
        int result = 0;
        for (int i = 0; i < 1000; ++i) {
            result += i * i;
        }
        std::cout << "Calculation result: " << result << std::endl;

        std::vector<int> numbers(100, 0);
        for (int i = 0; i < 100; ++i) {
            numbers[i] = i * 2;
        }
        std::cout << "Last number in array: " << numbers.back() << std::endl;
    }
};

int main() {
    UserManager manager;
    manager.addUser("alice", 1);
    manager.addUser("bob", 2);
    manager.addUser("charlie", 3);

    manager.processUserRequest("alice", "delete_file");
    manager.processUserRequest("bob", "delete_file");
    manager.processUserRequest("charlie", "modify_system_settings");

    return 0;
}