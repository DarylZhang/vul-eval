import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.SQLException;

class DummyProcessor {
    public static void process(String data) {
        String sanitizedInput = sanitizeInput(data);
        System.out.println("Processing: " + sanitizedInput);
    }

    public static String sanitizeInput(String input) {
        return input.replaceAll("['\"\\\\]", "").replaceAll("--", "");
    }
}

public class CWE_89_DatabaseQuery_fixed_2 {
    public static void main(String[] args) {
        String userInput = args[0];
        DummyProcessor.process(userInput);

        try {
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/testdb", "root", "password");
            Statement stmt = conn.createStatement();

            String sanitizedUserInput = DummyProcessor.sanitizeInput(userInput);
            String query = "SELECT * FROM users WHERE username = '" + sanitizedUserInput + "'";
            ResultSet rs = stmt.executeQuery(query);

            while (rs.next()) {
                System.out.println("User ID: " + rs.getInt("id"));
                System.out.println("Username: " + rs.getString("username"));
            }

            rs.close();
            stmt.close();
            conn.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}