import java.io.*;
import java.util.*;

public class DataManager_CWE_502_fixed {
    private List<String> dataList;
    private Random random;
    private DataValidator validator;

    public DataManager_CWE_502_fixed() {
        dataList = new ArrayList<>();
        random = new Random();
        validator = new DataValidator();
    }

    public void processInputData(String filename) {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(filename))) {
            Object obj = ois.readObject();
            // Avoid CWE-502 Vulnerable method: deserializes data without verification
            processDeserializedData(obj);
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
        performComplexOperations();
    }

    private void processDeserializedData(Object obj) {
        if (validator.isValidData(obj)) {
            dataList = (List<String>) obj;
        } else {
            System.out.println("Invalid data detected. Using default empty list.");
            dataList = new ArrayList<>();
        }
    }

    private void performComplexOperations() {
        for (int i = 0; i < dataList.size(); i++) {
            String item = dataList.get(i);
            if (i % 3 == 0) {
                item = item.toUpperCase();
            } else if (i % 3 == 1) {
                item = item.toLowerCase();
            }
            if (item.length() > 5) {
                item = item.substring(0, 5);
            }
            dataList.set(i, item);
        }
    }

    public void generateReport() {
        System.out.println("Data Report:");
        for (String item : dataList) {
            System.out.println(item + " - Length: " + item.length() + ", Hash: " + item.hashCode());
        }
        System.out.println("Total items: " + dataList.size());
        System.out.println("Random number: " + random.nextInt(1000));
    }

    public static void main(String[] args) {
        DataManager_CWE_502_fixed manager = new DataManager_CWE_502_fixed();
        manager.processInputData("data.ser");
        manager.generateReport();
    }

    private class DataValidator {
        public boolean isValidData(Object obj) {
            if (!(obj instanceof List)) {
                return false;
            }
            List<?> list = (List<?>) obj;
            for (Object item : list) {
                if (!(item instanceof String)) {
                    return false;
                }
                String str = (String) item;
                if (str.length() > 100 || !str.matches("[a-zA-Z0-9]+")) {
                    return false;
                }
            }
            return true;
        }
    }
}