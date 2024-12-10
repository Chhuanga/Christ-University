import java.util.Scanner;

public class IncomeTaxCalculator {

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
        double tax = 0;

        if (age < 60) {
            // Tax slabs for individuals below 60 years of age
            if (income <= 250000) {
                tax = 0;
            } else if (income <= 500000) {
                tax = (income - 250000) * 0.05;
            } else if (income <= 750000) {
                tax = 250000 * 0.05 + (income - 500000) * 0.10;
            } else if (income <= 1000000) {
                tax = 250000 * 0.05 + 250000 * 0.10 + (income - 750000) * 0.15;
            } else if (income <= 1250000) {
                tax = 250000 * 0.05 + 250000 * 0.10 + 250000 * 0.15 + (income - 1000000) * 0.20;
            } else if (income <= 1500000) {
                tax = 250000 * 0.05 + 250000 * 0.10 + 250000 * 0.15 + 250000 * 0.20 + (income - 1250000) * 0.25;
            } else {
                tax = 250000 * 0.05 + 250000 * 0.10 + 250000 * 0.15 + 250000 * 0.20 + 250000 * 0.25
                        + (income - 1500000) * 0.30;
            }
        } else if (age < 80) {
            // Tax slabs for individuals aged 60 to 80 years (Senior Citizens)
            if (income <= 300000) {
                tax = 0;
            } else if (income <= 500000) {
                tax = (income - 300000) * 0.05;
            } else if (income <= 750000) {
                tax = 200000 * 0.05 + (income - 500000) * 0.10;
            } else if (income <= 1000000) {
                tax = 200000 * 0.05 + 250000 * 0.10 + (income - 750000) * 0.15;
            } else if (income <= 1250000) {
                tax = 200000 * 0.05 + 250000 * 0.10 + 250000 * 0.15 + (income - 1000000) * 0.20;
            } else if (income <= 1500000) {
                tax = 200000 * 0.05 + 250000 * 0.10 + 250000 * 0.15 + 250000 * 0.20 + (income - 1250000) * 0.25;
            } else {
                tax = 200000 * 0.05 + 250000 * 0.10 + 250000 * 0.15 + 250000 * 0.20 + 250000 * 0.25
                        + (income - 1500000) * 0.30;
            }
        } else {
            // Tax slabs for individuals aged above 80 years (Super Senior Citizens)
            if (income <= 500000) {
                tax = 0;
            } else if (income <= 1000000) {
                tax = (income - 500000) * 0.20;
            } else if (income <= 1500000) {
                tax = 500000 * 0.20 + (income - 1000000) * 0.30;
            } else {
                tax = 500000 * 0.20 + 500000 * 0.30 + (income - 1500000) * 0.30;
            }
        }

        return tax;
    }
}