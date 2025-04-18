import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import org.apache.commons.text.StringEscapeUtils;  // 引入Apache的StringEscapeUtils库

@WebServlet("/dom")
public class CWE_79_event_fixed extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String userInput = request.getParameter("userContent");

        String safeInput = StringEscapeUtils.escapeHtml4(userInput);

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        out.println("<html><body>");
        out.println("<div id='content'></div>");
        out.println("<script>");
        out.println("document.getElementById('content').innerHTML = '" + safeInput + "';");
        out.println("</script>");
        out.println("</body></html>");
    }
}