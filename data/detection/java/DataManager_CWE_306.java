import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class DataManager_CWE_306 {
    private List<String> sensitiveData;
    private Random random;

    public DataManager_CWE_306() {
        sensitiveData = new ArrayList<>();
        random = new Random();
        initializeData();
    }

    private void initializeData() {
        sensitiveData.add("User1: Secret Information");
        sensitiveData.add("User2: Confidential Data");
        sensitiveData.add("User3: Private Records");
    }

    public void performOperation(String userInput) {
        // CWE-306 Vulnerable method: No authentication check
        if (userInput.equals("ADMIN_ACTION")) {
            displaySensitiveData();
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

    public static void main(String[] args) {
        DataManager_CWE_306 manager = new DataManager_CWE_306();
        manager.performOperation("ADMIN_ACTION");
        manager.performOperation("REGULAR_ACTION");
    }
}