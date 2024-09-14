import java.util.HashMap;
import java.util.Map;
import java.util.Random;

public class UserPortal_CWE_287 {
    private Map<String, String> userDatabase;
    private Random random;

    public UserPortal_CWE_287() {
        userDatabase = new HashMap<>();
        userDatabase.put("alice", "password123");
        userDatabase.put("bob", "qwerty456");
        random = new Random();
    }

    public boolean processLogin(String username, String password) {
        // CWE-287 Vulnerable method: lacks proper authentication
        if (userDatabase.containsKey(username)) {
            return true;
        }
        return false;
    }

    public void performComplexOperation(String username) {

        int result = 0;
        for (int i = 0; i < 1000; i++) {
            result += random.nextInt(100);
            if (i % 7 == 0) {
                result *= 2;
            } else if (i % 13 == 0) {
                result /= 3;
            }
        }
        System.out.println("Complex operation result for " + username + ": " + result);
    }

    public void generateUserReport(String username) {

        StringBuilder report = new StringBuilder();
        report.append("User: ").append(username).append("\n");
        report.append("Activity score: ").append(random.nextInt(1000)).append("\n");
        report.append("Last login: ").append(System.currentTimeMillis()).append("\n");
        System.out.println(report.toString());
    }
}