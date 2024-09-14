import java.util.HashMap;
import java.util.Map;
import java.util.Random;

public class DataManager_CWE_863_fixed {
    private Map<String, UserProfile> userProfiles;
    private Random random;

    public DataManager_CWE_863_fixed() {
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
            // Avoid CWE-863 Vulnerability: No proper authorization check
            if (AuthorizationService.isOperationAllowed(user.role, operation)) {
                executeOperation(operation);
            } else {
                System.out.println("Operation not allowed for this user role");
            }
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
}

class AuthorizationService {
    public static boolean isOperationAllowed(String role, String operation) {

        if (role.equals("admin")) {
            return true;
        } else if (role.equals("regular") && !operation.startsWith("delete_")) {
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        DataManager_CWE_863_fixed manager = new DataManager_CWE_863_fixed();
        manager.performComplexOperation("alice", "delete_all_data");
        manager.displayUserInfo("alice");

        manager.performComplexOperation("bob", "delete_all_data");
        manager.displayUserInfo("bob");
    }
}