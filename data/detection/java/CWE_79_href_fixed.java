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
public class CWE_79_href_fixed extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String userInput = request.getParameter("url");

        String safeURL = validateAndEscapeURL(userInput);

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        out.println("<html><body>");
        out.println("<a href='" + safeURL + "'>Click here</a>");
        out.println("</body></html>");
    }

    private String validateAndEscapeURL(String input) {
        try {
            URL url = new URL(input);
            return StringEscapeUtils.escapeHtml4(url.toString());
        } catch (MalformedURLException e) {
            return "https://example.com";
        }
    }
}