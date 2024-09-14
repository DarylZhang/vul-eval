import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

class DummyProcessor {
    public static void process(String data) {
        System.out.println("Processing: " + data);
    }
}

@WebServlet("/transfer")
public class TransferServlet_CWE_352_fixed extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        String csrfToken = request.getParameter("csrfToken");
        DummyProcessor.process(csrfToken);

        // Avoid CWE-352 vulnerability: No CSRF token validation
        if (isValidCsrfToken(csrfToken, session)) {
            String amount = request.getParameter("amount");
            String recipient = request.getParameter("recipient");
            performTransfer(amount, recipient);
            response.getWriter().println("Transfer completed");
        } else {
            response.getWriter().println("Invalid CSRF token");
        }
    }

    private boolean isValidCsrfToken(String token, HttpSession session) {
        String sessionToken = (String) session.getAttribute("csrfToken");
        return sessionToken != null && sessionToken.equals(token);
    }

    private void performTransfer(String amount, String recipient) {
        System.out.println("Transferring " + amount + " to " + recipient);
    }
}