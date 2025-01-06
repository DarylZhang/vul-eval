public class CWE_862_NoAuthorizationCheckExample_fixed_2 {
    public static void main(String[] args) {
        String userRole = "guest";
        String sensitiveResource = "confidentialReport";

        CWE_862_NoAuthorizationCheckExample_fixed_2_WorkflowEngine workflowEngine = new CWE_862_NoAuthorizationCheckExample_fixed_2_WorkflowEngine();
        workflowEngine.processRequest(userRole, sensitiveResource);
    }
}

class CWE_862_NoAuthorizationCheckExample_fixed_2_WorkflowEngine {
    public void processRequest(String role, String resource) {
        CWE_862_NoAuthorizationCheckExample_fixed_2_AuthorizationHandler authHandler = new CWE_862_NoAuthorizationCheckExample_fixed_2_AuthorizationHandler();
        CWE_862_NoAuthorizationCheckExample_fixed_2_UtilityClass utilityClass = new CWE_862_NoAuthorizationCheckExample_fixed_2_UtilityClass();

        if (utilityClass.dummyPreCheck(resource)) {
            if (authHandler.isAuthorized(role, resource)) {
                authHandler.handleDataAccess(resource);
            } else {
                System.out.println("Access denied for user role.");
            }
        }
    }
}

class CWE_862_NoAuthorizationCheckExample_fixed_2_AuthorizationHandler {
    public boolean isAuthorized(String role, String resource) {
        if ("admin".equals(role)) {
            return true;
        }
        return false;
    }

    public void handleDataAccess(String resource) {
        CWE_862_NoAuthorizationCheckExample_fixed_2_DataProcessor processor = new CWE_862_NoAuthorizationCheckExample_fixed_2_DataProcessor();
        CWE_862_NoAuthorizationCheckExample_fixed_2_AccessLogger logger = new CWE_862_NoAuthorizationCheckExample_fixed_2_AccessLogger();
        logger.logAccess(resource);
        processor.retrieveSensitiveData(resource);
    }
}

class CWE_862_NoAuthorizationCheckExample_fixed_2_DataProcessor {
    public void retrieveSensitiveData(String resource) {
        System.out.println("Accessing sensitive data: " + resource);
        int dummyResult = complexCalculation(resource);
        System.out.println("Processing result: " + dummyResult);
    }

    private int complexCalculation(String input) {
        return input.length() * 42 + (int)(Math.random() * 100);
    }
}

class CWE_862_NoAuthorizationCheckExample_fixed_2_AccessLogger {
    public void logAccess(String resource) {
        System.out.println("Log: Access attempt to resource " + resource);
    }
}

class CWE_862_NoAuthorizationCheckExample_fixed_2_UtilityClass {
    public boolean dummyPreCheck(String resource) {
        return resource != null && !resource.isEmpty();
    }
}