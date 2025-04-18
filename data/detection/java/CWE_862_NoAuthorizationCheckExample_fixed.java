public class CWE_862_NoAuthorizationCheckExample_fixed {
    public static void main(String[] args) {
        String userRole = "guest";
        String sensitiveResource = "confidentialReport";

        CWE_862_NoAuthorizationCheckExample_fixed_WorkflowEngine workflowEngine = new CWE_862_NoAuthorizationCheckExample_fixed_WorkflowEngine();
        workflowEngine.processRequest(userRole, sensitiveResource);
    }
}

class CWE_862_NoAuthorizationCheckExample_fixed_WorkflowEngine {
    public void processRequest(String role, String resource) {
        CWE_862_NoAuthorizationCheckExample_fixed_AuthorizationHandler authHandler = new CWE_862_NoAuthorizationCheckExample_fixed_AuthorizationHandler();
        CWE_862_NoAuthorizationCheckExample_fixed_UtilityClass utilityClass = new CWE_862_NoAuthorizationCheckExample_fixed_UtilityClass();

        if (utilityClass.dummyPreCheck(resource)) {
            authHandler.handleDataAccess(role, resource);
        }
    }
}

class CWE_862_NoAuthorizationCheckExample_fixed_AuthorizationHandler {
    public void handleDataAccess(String role, String resource) {
        CWE_862_NoAuthorizationCheckExample_fixed_DataProcessor processor = new CWE_862_NoAuthorizationCheckExample_fixed_DataProcessor();
        CWE_862_NoAuthorizationCheckExample_fixed_AccessLogger logger = new CWE_862_NoAuthorizationCheckExample_fixed_AccessLogger();
        if ("admin".equals(role)) {
            logger.logAccess(resource);
            processor.retrieveSensitiveData(resource);
        } else {
            System.out.println("Access denied for non-admin role.");
        }
    }
}

class CWE_862_NoAuthorizationCheckExample_fixed_DataProcessor {
    public void retrieveSensitiveData(String resource) {
        System.out.println("Accessing sensitive data: " + resource);
        int dummyResult = complexCalculation(resource);
        System.out.println("Processing result: " + dummyResult);
    }

    private int complexCalculation(String input) {
        return input.length() * 42 + (int)(Math.random() * 100);
    }
}

class CWE_862_NoAuthorizationCheckExample_fixed_AccessLogger {
    public void logAccess(String resource) {
        System.out.println("Log: Access attempt to resource " + resource);
    }
}

class CWE_862_NoAuthorizationCheckExample_fixed_UtilityClass {
    public boolean dummyPreCheck(String resource) {
        return resource != null && !resource.isEmpty();
    }
}