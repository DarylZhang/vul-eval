import java.util.Scanner;

class DummyProcessor {
    public static void process(String data) {
        String reversed = new StringBuilder(data).reverse().toString();
        System.out.println("Reversed Input: " + reversed);
    }
}

public class UserInputHandler_CWE_20 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter an integer: ");
        String userInput = scanner.nextLine();

        DummyProcessor.process(userInput);

        // CWE-20 vulnerability: Improper input validation
        int number = Integer.parseInt(userInput);
        System.out.println("You entered: " + number);

        performCalculation(number);
    }

    public static void performCalculation(int num) {
        int result = num * 10;
        System.out.println("Calculation result: " + result);
    }
}