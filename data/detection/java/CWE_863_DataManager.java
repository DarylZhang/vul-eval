import java.util.HashMap;
import java.util.Map;
import java.util.Random;

public class CWE_863_DataManager {
    private Map<String, UserProfile> userProfiles;
    private Random random;

    public CWE_863_DataManager() {
        userProfiles = new HashMap<>();
        random = new Random();
        initializeUsers();
    }

    private void initializeUsers() {
        userProfiles.put("alice", new UserProfile("alice", "regular"));
        userProfiles.put("bob", new UserProfile("bob", "admin"));
    }

    public void performComplexOperation(String username, String operation) {
        UserProfile user = userProfiles.get(username);
        if (user != null) {
            executeOperation(operation);
        } else {
            System.out.println("User not found");
        }
    }

    private void executeOperation(String operation) {
        System.out.println("Executing operation: " + operation);

        for (int i = 0; i < 1000; i++) {
            double result = Math.pow(i, 2) + Math.sqrt(i);
            if (result % 2 == 0) {
                System.out.println("Even result: " + result);
            }
        }
    }

    public void displayUserInfo(String username) {
        UserProfile user = userProfiles.get(username);
        if (user != null) {
            System.out.println("Username: " + user.username);
            System.out.println("Role: " + user.role);
        } else {
            System.out.println("User not found");
        }
    }

    private class UserProfile {
        String username;
        String role;

        UserProfile(String username, String role) {
            this.username = username;
            this.role = role;
        }
    }

    public static void main(String[] args) {
        CWE_863_DataManager manager = new CWE_863_DataManager();
        manager.performComplexOperation("alice", "delete_all_data");
        manager.displayUserInfo("alice");
    }
}