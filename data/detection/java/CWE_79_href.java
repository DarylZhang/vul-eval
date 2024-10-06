import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import org.apache.commons.text.StringEscapeUtils;
import java.net.URL;
import java.net.MalformedURLException;

@WebServlet("/redirect")
public class CWE_79_href extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String userInput = request.getParameter("url");

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        out.println("<html><body>");
        // CWE-79 XSS vulnerability: userInput is used directly in a URL
        out.println("<a href='" + userInput + "'>Click here</a>");
        out.println("</body></html>");
    }
}