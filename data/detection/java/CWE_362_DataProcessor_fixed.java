import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.concurrent.locks.ReentrantLock;

public class CWE_362_DataProcessor_fixed {
    private List<Integer> sharedData = new ArrayList<>();
    private Random random = new Random();
    private ReentrantLock lock = new ReentrantLock();

    public void processInformation(int value) {
        // Avoid CWE-362 Vulnerability: No synchronization on shared resource
        lock.lock();
        try {
            sharedData.add(value);

            for (int i = 0; i < 1000; i++) {
                double result = Math.pow(i, 2) + Math.sqrt(i);
                if (result % 2 == 0) {
                    System.out.println("Even result: " + result);
                }
            }

            int size = sharedData.size();
            System.out.println("Current data size: " + size);
        } finally {
            lock.unlock();
        }
    }

    public void analyzeData() {
        lock.lock();
        try {
            int sum = 0;
            for (int num : sharedData) {
                sum += num;
                if (random.nextBoolean()) {
                    System.out.println("Random number: " + random.nextInt(100));
                }
            }
            System.out.println("Data analysis result: " + sum);
        } finally {
            lock.unlock();
        }
    }

    public void clearOldRecords() {
        // Avoid CWE-362 Vulnerability: No synchronization on shared resource
        lock.lock();
        try {
            int halfSize = sharedData.size() / 2;
            for (int i = 0; i < halfSize; i++) {
                sharedData.remove(0);
            }
            System.out.println("Old records cleared.");
        } finally {
            lock.unlock();
        }
    }
}

class SynchronizationManager {
    private static ReentrantLock globalLock = new ReentrantLock();

    public static void acquireLock() {
        globalLock.lock();
    }

    public static void releaseLock() {
        globalLock.unlock();
    }

    public static boolean tryLock() {
        return globalLock.tryLock();
    }
}