import java.sql.*;
import java.util.Scanner;

public class FinanceManagement {
    private static final String URL = "jdbc:mysql://localhost:3306/finance_management";
    private static final String USER = "root";
    private static final String PASSWORD = "password";

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("Finance Management System");
            System.out.println("1. Add Transaction");
            System.out.println("2. View Transactions");
            System.out.println("3. Update Transaction");
            System.out.println("4. Delete Transaction");
            System.out.println("5. Exit");
            System.out.print("Choose an option: ");
            int choice = scanner.nextInt();
            scanner.nextLine(); // consume newline

            switch (choice) {
                case 1:
                    addTransaction(scanner);
                    break;
                case 2:
                    viewTransactions();
                    break;
                case 3:
                    updateTransaction(scanner);
                    break;
                case 4:
                    deleteTransaction(scanner);
                    break;
                case 5:
                    System.out.println("Exiting...");
                    return;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }

    private static void addTransaction(Scanner scanner) {
        System.out.print("Enter description: ");
        String description = scanner.nextLine();
        System.out.print("Enter amount: ");
        double amount = scanner.nextDouble();
        System.out.print("Enter transaction date (YYYY-MM-DD): ");
        String date = scanner.next();

        try (Connection conn = DriverManager.getConnection(URL, USER, PASSWORD);
                PreparedStatement stmt = conn.prepareStatement(
                        "INSERT INTO transactions (description, amount, transaction_date) VALUES (?, ?, ?)")) {
            stmt.setString(1, description);
            stmt.setDouble(2, amount);
            stmt.setDate(3, Date.valueOf(date));
            stmt.executeUpdate();
            System.out.println("Transaction added successfully.");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void viewTransactions() {
        try (Connection conn = DriverManager.getConnection(URL, USER, PASSWORD);
                Statement stmt = conn.createStatement();
                ResultSet rs = stmt.executeQuery("SELECT * FROM transactions")) {
            while (rs.next()) {
                System.out.println("ID: " + rs.getInt("id"));
                System.out.println("Description: " + rs.getString("description"));
                System.out.println("Amount: " + rs.getDouble("amount"));
                System.out.println("Date: " + rs.getDate("transaction_date"));
                System.out.println("-----");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void updateTransaction(Scanner scanner) {
        System.out.print("Enter transaction ID to update: ");
        int id = scanner.nextInt();
        scanner.nextLine(); // consume newline
        System.out.print("Enter new description: ");
        String description = scanner.nextLine();
        System.out.print("Enter new amount: ");
        double amount = scanner.nextDouble();
        System.out.print("Enter new transaction date (YYYY-MM-DD): ");
        String date = scanner.next();

        try (Connection conn = DriverManager.getConnection(URL, USER, PASSWORD);
                PreparedStatement stmt = conn.prepareStatement(
                        "UPDATE transactions SET description = ?, amount = ?, transaction_date = ? WHERE id = ?")) {
            stmt.setString(1, description);
            stmt.setDouble(2, amount);
            stmt.setDate(3, Date.valueOf(date));
            stmt.setInt(4, id);
            stmt.executeUpdate();
            System.out.println("Transaction updated successfully.");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void deleteTransaction(Scanner scanner) {
        System.out.print("Enter transaction ID to delete: ");
        int id = scanner.nextInt();

        try (Connection conn = DriverManager.getConnection(URL, USER, PASSWORD);
                PreparedStatement stmt = conn.prepareStatement("DELETE FROM transactions WHERE id = ?")) {
            stmt.setInt(1, id);
            stmt.executeUpdate();
            System.out.println("Transaction deleted successfully.");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}