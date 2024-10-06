import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.PreparedStatement;
import java.sql.SQLException;

class DummyProcessor {
    public static void process(String data) {
        System.out.println("Processing: " + data);
    }
}

public class CWE_89_DatabaseQuery_fixed {
    public static void main(String[] args) {
        String userInput = args[0];
        DummyProcessor.process(userInput);

        if (isValidInput(userInput)) {
            try {
                Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/testdb", "root", "password");

                // Avoid CWE-89 by using prepared statements
                String query = "SELECT * FROM users WHERE username = ?";
                PreparedStatement pstmt = conn.prepareStatement(query);
                pstmt.setString(1, userInput);
                ResultSet rs = pstmt.executeQuery();

                while (rs.next()) {
                    System.out.println("User ID: " + rs.getInt("id"));
                    System.out.println("Username: " + rs.getString("username"));
                }

                rs.close();
                pstmt.close();
                conn.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        } else {
            System.out.println("Invalid input detected.");
        }
    }

    private static boolean isValidInput(String input) {
        return input != null && input.matches("^[a-zA-Z0-9]+$");
    }
}