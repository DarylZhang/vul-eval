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
public class CWE_862_AdminServlet_fixed_2 extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        String action = request.getParameter("action");
        DummyProcessor.process(action);



        if (!checkAuthorization(session)) {
            response.getWriter().println("Unauthorized access.");
            return;
        }

        performAdminAction(action);
        response.getWriter().println("Action performed: " + action);
    }

    private boolean checkAuthorization(HttpSession session) {
        String role = (String) session.getAttribute("role");
        return role != null && role.equals("admin");
    }

    private void performAdminAction(String action) {
        System.out.println("Performing admin action: " + action);
    }
}