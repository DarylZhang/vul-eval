import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class CWE_362_DataProcessor {
    private List<Integer> sharedData = new ArrayList<>();
    private Random random = new Random();

    public void processInformation(int value) {

        // CWE-362 Vulnerability: No synchronization on shared resource
        sharedData.add(value);

        for (int i = 0; i < 1000; i++) {
            double result = Math.pow(i, 2) + Math.sqrt(i);
            if (result % 2 == 0) {
                System.out.println("Even result: " + result);
            }
        }

        int size = sharedData.size();
        System.out.println("Current data size: " + size);
    }

    public void analyzeData() {
        int sum = 0;
        for (int num : sharedData) {
            sum += num;
            if (random.nextBoolean()) {
                System.out.println("Random number: " + random.nextInt(100));
            }
        }
        System.out.println("Data analysis result: " + sum);
    }

    public void clearOldRecords() {
        // CWE-362 Vulnerability: No synchronization on shared resource
        int halfSize = sharedData.size() / 2;
        for (int i = 0; i < halfSize; i++) {
            sharedData.remove(0);
        }
        System.out.println("Old records cleared.");
    }
}