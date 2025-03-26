import java.sql.*;
import java.util.Scanner;

public class LibraryManager {
    private static final String URL = "jdbc:mysql://localhost:3306/library";
    private static final String USER = "root";
    private static final String PASSWORD = "password";

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("1. Create");
            System.out.println("2. Read");
            System.out.println("3. Update");
            System.out.println("4. Delete");
            System.out.println("5. Exit");
            System.out.print("Choose an option: ");
            int choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 1:
                    createBook(scanner);
                    break;
                case 2:
                    readBooks();
                    break;
                case 3:
                    updateBook(scanner);
                    break;
                case 4:
                    deleteBook(scanner);
                    break;
                case 5:
                    System.exit(0);
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }

    private static void createBook(Scanner scanner) {
        System.out.print("Enter BookID: ");
        int bookID = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Enter Title: ");
        String title = scanner.nextLine();
        System.out.print("Enter Author: ");
        String author = scanner.nextLine();
        System.out.print("Enter Genre: ");
        String genre = scanner.nextLine();
        System.out.print("Enter Price: ");
        double price = scanner.nextDouble();

        try (Connection conn = DriverManager.getConnection(URL, USER, PASSWORD);
                PreparedStatement stmt = conn.prepareStatement(
                        "INSERT INTO books (BookID, Title, Author, Genre, Price) VALUES (?, ?, ?, ?, ?)")) {
            stmt.setInt(1, bookID);
            stmt.setString(2, title);
            stmt.setString(3, author);
            stmt.setString(4, genre);
            stmt.setDouble(5, price);
            stmt.executeUpdate();
            System.out.println("Book added successfully.");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void readBooks() {
        try (Connection conn = DriverManager.getConnection(URL, USER, PASSWORD);
                Statement stmt = conn.createStatement();
                ResultSet rs = stmt.executeQuery("SELECT * FROM books")) {
            while (rs.next()) {
                System.out.println("BookID: " + rs.getInt("BookID"));
                System.out.println("Title: " + rs.getString("Title"));
                System.out.println("Author: " + rs.getString("Author"));
                System.out.println("Genre: " + rs.getString("Genre"));
                System.out.println("Price: " + rs.getDouble("Price"));
                System.out.println();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void updateBook(Scanner scanner) {
        System.out.print("Enter BookID to update: ");
        int bookID = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Enter new Title: ");
        String title = scanner.nextLine();
        System.out.print("Enter new Author: ");
        String author = scanner.nextLine();
        System.out.print("Enter new Genre: ");
        String genre = scanner.nextLine();
        System.out.print("Enter new Price: ");
        double price = scanner.nextDouble();

        try (Connection conn = DriverManager.getConnection(URL, USER, PASSWORD);
                PreparedStatement stmt = conn.prepareStatement(
                        "UPDATE books SET Title = ?, Author = ?, Genre = ?, Price = ? WHERE BookID = ?")) {
            stmt.setString(1, title);
            stmt.setString(2, author);
            stmt.setString(3, genre);
            stmt.setDouble(4, price);
            stmt.setInt(5, bookID);
            stmt.executeUpdate();
            System.out.println("Book updated successfully.");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void deleteBook(Scanner scanner) {
        System.out.print("Enter BookID to delete: ");
        int bookID = scanner.nextInt();

        try (Connection conn = DriverManager.getConnection(URL, USER, PASSWORD);
                PreparedStatement stmt = conn.prepareStatement("DELETE FROM books WHERE BookID = ?")) {
            stmt.setInt(1, bookID);
            stmt.executeUpdate();
            System.out.println("Book deleted successfully.");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}