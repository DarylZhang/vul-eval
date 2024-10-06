import java.util.Random;

class ProcessHandler {

    public static void startProcess(int permissionLevel, String sensitiveData) {
        Random rand = new Random();
        int dummyVar1 = rand.nextInt(100);
        String dummyVar2 = dummyLogicMethod1(dummyVar1);

        if (dummyVar2.equals("SPECIAL_CASE")) {
            complexMethod();
        }

        accessSensitiveFunction(permissionLevel, sensitiveData);

        additionalLogic();
    }

    private static String dummyLogicMethod1(int input) {
        return input > 50 ? "SPECIAL_CASE" : "NORMAL_CASE";
    }

    private static void complexMethod() {
        for (int i = 0; i < 1000; i++) {
            if (i % 100 == 0) {
                dummyLogicMethod2(i);
            }
        }
    }

    private static void dummyLogicMethod2(int counter) {
        while (counter > 0) {
            counter--;
        }
    }

    private static void accessSensitiveFunction(int level, String data) {
        if (level > 5) {
            System.out.println("Accessing sensitive data: " + data);
        } else {
            System.out.println("Insufficient permission level.");
        }
    }

    private static void additionalLogic() {
        int dummyVar3 = 5;
        for (int i = 0; i < dummyVar3; i++) {
            dummyVar3 += i * 2;
        }
    }
}

public class CWE_306_DataManager_fixed_2 {
    public static void main(String[] args) {
        int userPermissionLevel = 3;
        String sensitiveInformation = "TopSecretData";

        if (!CWE_306_DataManager_fixed_2.checkPermission(userPermissionLevel)) {
            System.out.println("Access denied.");
            return;
        }

        ProcessHandler.startProcess(userPermissionLevel, sensitiveInformation);
    }

    private static boolean checkPermission(int level) {
        return level >= 5;
    }
}