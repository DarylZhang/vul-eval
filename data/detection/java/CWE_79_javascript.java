import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/dom")
public class CWE_79_javascript extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String userInput = request.getParameter("userContent");

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        out.println("<html><body>");
        out.println("<div id='content'></div>");
        out.println("<script>");
        // CWE-79 XSS vulnerability: userInput is injected into DOM using innerHTML
        out.println("document.getElementById('content').innerHTML = '" + userInput + "';");
        out.println("</script>");
        out.println("</body></html>");
    }
}