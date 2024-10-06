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

@WebServlet("/admin")
public class CWE_862_AdminServlet_fixed extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        String action = request.getParameter("action");
        DummyProcessor.process(action);

        // Avoid CWE-862 vulnerability: No authorization check
        if (isUserAuthorized(session)) {
            performAdminAction(action);
            response.getWriter().println("Action performed: " + action);
        } else {
            response.getWriter().println("Unauthorized access");
        }
    }

    private boolean isUserAuthorized(HttpSession session) {
        String role = (String) session.getAttribute("role");
        return "admin".equals(role);
    }

    private void performAdminAction(String action) {
        System.out.println("Performing admin action: " + action);
    }
}