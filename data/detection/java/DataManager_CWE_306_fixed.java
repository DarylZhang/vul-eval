import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class DataManager_CWE_306_fixed {
    private List<String> sensitiveData;
    private Random random;
    private AuthenticationService authService;

    public DataManager_CWE_306_fixed() {
        sensitiveData = new ArrayList<>();
        random = new Random();
        authService = new AuthenticationService();
        initializeData();
    }

    private void initializeData() {
        sensitiveData.add("User1: Secret Information");
        sensitiveData.add("User2: Confidential Data");
        sensitiveData.add("User3: Private Records");
    }

    public void performOperation(String userInput, String username, String password) {
        if (userInput.equals("ADMIN_ACTION")) {
            // Avoid CWE-306 Vulnerable method: No authentication check
            if (authService.authenticate(username, password)) {
                displaySensitiveData();
            } else {
                System.out.println("Authentication failed. Access denied.");
            }
        } else {
            performRegularOperation(userInput);
        }
    }

    private void displaySensitiveData() {
        System.out.println("Displaying sensitive data:");
        for (String data : sensitiveData) {
            System.out.println(data);
        }
    }

    private void performRegularOperation(String input) {
        int result = 0;
        for (int i = 0; i < 1000; i++) {
            if (i % 3 == 0) {
                result += random.nextInt(100);
            } else if (i % 7 == 0) {
                result -= random.nextInt(50);
            } else {
                result += i;
            }

            if (result > 10000) {
                result %= 10000;
            }
        }
        System.out.println("Regular operation result: " + result);
        System.out.println("Input processed: " + input);
    }

    private class AuthenticationService {
        public boolean authenticate(String username, String password) {
            return "admin".equals(username) && "securePassword123".equals(password);
        }
    }

    public static void main(String[] args) {
        DataManager_CWE_306_fixed manager = new DataManager_CWE_306_fixed();
        manager.performOperation("ADMIN_ACTION", "admin", "securePassword123");
        manager.performOperation("ADMIN_ACTION", "user", "wrongPassword");
        manager.performOperation("REGULAR_ACTION", "", "");
    }
}