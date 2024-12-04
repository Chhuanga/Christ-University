public class SharedDigit {

    public static boolean hasSharedDigit(int num1, int num2) {
        // Checking if numbers are within the range of 10 to 99
        if (num1 < 10 || num1 > 99 || num2 < 10 || num2 > 99) {
            return false;
        }

        // Extracts digits of num1
        int num1FirstDigit = num1 / 10;
        int num1SecondDigit = num1 % 10;

        //  Extracts digits of num2
        int num2FirstDigit = num2 / 10;
        int num2SecondDigit = num2 % 10;

        if (num1FirstDigit == num2FirstDigit || num1FirstDigit == num2SecondDigit ||
            num1SecondDigit == num2FirstDigit || num1SecondDigit == num2SecondDigit) {
            return true;
        }

        return false;
    }

    public static void main(String[] args) {
        // Test cases taken from question paper
        System.out.println(hasSharedDigit(12, 23)); // should return true
        System.out.println(hasSharedDigit(9, 99));  // should return false
        System.out.println(hasSharedDigit(15, 55)); // should return true
    }
}