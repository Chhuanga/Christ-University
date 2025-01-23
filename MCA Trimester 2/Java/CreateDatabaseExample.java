import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;
import java.sql.ResultSet;

public class CreateDatabaseExample {
    public static void main(String[] args) {
        // MySQL server credentials
        String serverUrl = "jdbc:mysql://localhost:3306/";
        String user = "root"; // Replace with your MySQL username
        String password = "your_password"; // Replace with your MySQL password
        String databaseName = "dynamicdb";

        // JDBC objects
        Connection connection = null;
        Statement statement = null;

        try {
            // Step 1: Connect to the MySQL server (not a specific database)
            connection = DriverManager.getConnection(serverUrl, user, password);
            statement = connection.createStatement();
            System.out.println("Connected to MySQL server!");

            // Step 2: Create the database if it doesn't exist
            String createDatabaseSQL = "CREATE DATABASE IF NOT EXISTS " + databaseName;
            statement.execute(createDatabaseSQL);
            System.out.println("Database '" + databaseName + "' created (if it didn't exist).");

            // Step 3: Connect to the newly created database
            String databaseUrl = serverUrl + databaseName;
            connection = DriverManager.getConnection(databaseUrl, user, password);
            statement = connection.createStatement();
            System.out.println("Connected to the database: " + databaseName);

            // Step 4: Create a table
            String createTableSQL = "CREATE TABLE IF NOT EXISTS sample_table ("
                    + "id INT AUTO_INCREMENT PRIMARY KEY, "
                    + "name VARCHAR(100) NOT NULL)";
            statement.execute(createTableSQL);
            System.out.println("Table 'sample_table' created successfully!");

            // Step 5: Insert sample data
            String insertDataSQL = "INSERT INTO sample_table (name) VALUES ('Alice'), ('Bob'), ('Charlie')";
            statement.executeUpdate(insertDataSQL);
            System.out.println("Sample data inserted successfully!");

            // Step 6: Query the table
            String querySQL = "SELECT * FROM sample_table";
            ResultSet resultSet = statement.executeQuery(querySQL);

            // Display results
            System.out.println("Data from the table:");
            while (resultSet.next()) {
                System.out.println("ID: " + resultSet.getInt("id") +
                        ", Name: " + resultSet.getString("name"));
            }

            resultSet.close(); // Close ResultSet
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if (statement != null)
                    statement.close();
                if (connection != null)
                    connection.close();
            } catch (Exception ex) {
                ex.printStackTrace();
            }
        }
    }
}
