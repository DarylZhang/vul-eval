import java.io.*;
import java.util.*;

public class CWE_502_DataManager {
    private List<String> dataList;
    private Random random;

    public CWE_502_DataManager() {
        dataList = new ArrayList<>();
        random = new Random();
    }

    public void processInputData(String filename) {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(filename))) {

            Object obj = ois.readObject();

            if (obj instanceof List) {
                dataList = (List<String>) obj;
            }
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
        performComplexOperations();
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
        CWE_502_DataManager manager = new CWE_502_DataManager();
        manager.processInputData("data.ser");
        manager.generateReport();
    }
}