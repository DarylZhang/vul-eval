import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import org.apache.commons.text.StringEscapeUtils;

@WebServlet("/script")
public class CWE_79_javascript_fixed extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String userInput = request.getParameter("userScript");

        String safeInput = StringEscapeUtils.escapeHtml4(userInput);

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        out.println("<html><body>");
        out.println("<script>");
        out.println("alert('" + safeInput + "');");
        out.println("</script>");
        out.println("</body></html>");
    }
}