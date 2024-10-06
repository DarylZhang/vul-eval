public class CWE_862_NoAuthorizationCheckExample_fixed_2 {
    public static void main(String[] args) {
        String userRole = "guest";
        String sensitiveResource = "confidentialReport";

        WorkflowEngine workflowEngine = new WorkflowEngine();
        workflowEngine.processRequest(userRole, sensitiveResource);
    }
}

class WorkflowEngine {
    public void processRequest(String role, String resource) {
        AuthorizationHandler authHandler = new AuthorizationHandler();
        UtilityClass utilityClass = new UtilityClass();

        if (utilityClass.dummyPreCheck(resource)) {
            if (authHandler.isAuthorized(role, resource)) {
                authHandler.handleDataAccess(resource);
            } else {
                System.out.println("Access denied for user role.");
            }
        }
    }
}

class AuthorizationHandler {
    public boolean isAuthorized(String role, String resource) {
        if ("admin".equals(role)) {
            return true;
        }
        return false;
    }

    public void handleDataAccess(String resource) {
        DataProcessor processor = new DataProcessor();
        AccessLogger logger = new AccessLogger();
        logger.logAccess(resource);
        processor.retrieveSensitiveData(resource);
    }
}

class DataProcessor {
    public void retrieveSensitiveData(String resource) {
        System.out.println("Accessing sensitive data: " + resource);
        int dummyResult = complexCalculation(resource);
        System.out.println("Processing result: " + dummyResult);
    }

    private int complexCalculation(String input) {
        return input.length() * 42 + (int)(Math.random() * 100);
    }
}

class AccessLogger {
    public void logAccess(String resource) {
        System.out.println("Log: Access attempt to resource " + resource);
    }
}

class UtilityClass {
    public boolean dummyPreCheck(String resource) {
        return resource != null && !resource.isEmpty();
    }
}