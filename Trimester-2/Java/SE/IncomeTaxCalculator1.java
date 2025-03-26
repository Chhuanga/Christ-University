import java.util.Scanner;

public class IncomeTaxCalculator1 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input annual income and age
        System.out.print("Enter your annual income: ");
        double income = scanner.nextDouble();
        System.out.print("Enter your age: ");
        int age = scanner.nextInt();

        // Validate income and age
        if (income <= 0) {
            System.out.println("Invalid Income");
            return;
        }
        if (age < 18) {
            System.out.println("Invalid Age");
            return;
        }

        // Calculate tax based on age and income
        double tax = calculateTax(income, age);
        System.out.printf("The calculated tax is: ₹%.2f\n", tax);
    }

    public static double calculateTax(double income, int age) {
        double[] slabs;
        double[] rates;

        if (age < 60) {
            slabs = new double[] { 250000, 500000, 750000, 1000000, 1250000, 1500000 };
            rates = new double[] { 0.05, 0.10, 0.15, 0.20, 0.25, 0.30 };
        } else if (age < 80) {
            slabs = new double[] { 300000, 500000, 750000, 1000000, 1250000, 1500000 };
            rates = new double[] { 0.05, 0.10, 0.15, 0.20, 0.25, 0.30 };
        } else {
            slabs = new double[] { 500000, 1000000, 1500000 };
            rates = new double[] { 0.20, 0.30, 0.30 };
        }

        double tax = 0;
        for (int i = slabs.length - 1; i >= 0; i--) {
            if (income > slabs[i]) {
                tax += (income - slabs[i]) * rates[i];
                income = slabs[i];
            }
        }

        return tax;
    }
}