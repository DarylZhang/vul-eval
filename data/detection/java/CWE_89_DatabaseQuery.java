import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.SQLException;

class DummyProcessor {
    public static void process(String data) {
        System.out.println("Processing: " + data);
    }
}

public class CWE_89_DatabaseQuery {
    public static void main(String[] args) {
        String userInput = args[0];
        DummyProcessor.process(userInput);

        try {
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/testdb", "root", "password");
            Statement stmt = conn.createStatement();

            // CWE-89 vulnerability: Improper neutralization of special elements in SQL command
            String query = "SELECT * FROM users WHERE username = '" + userInput + "'";
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