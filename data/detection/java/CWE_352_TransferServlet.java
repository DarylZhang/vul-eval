import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

class CWE_352_TransferServlet_DummyProcessor {
    public static void process(String data) {
        System.out.println("Processing: " + data);
    }
}

@WebServlet("/transfer")
public class CWE_352_TransferServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String amount = request.getParameter("amount");
        String recipient = request.getParameter("recipient");
        CWE_352_TransferServlet_DummyProcessor.process(amount);

        performTransfer(amount, recipient);

        response.getWriter().println("Transfer completed");
    }

    private void performTransfer(String amount, String recipient) {
        System.out.println("Transferring " + amount + " to " + recipient);
    }
}