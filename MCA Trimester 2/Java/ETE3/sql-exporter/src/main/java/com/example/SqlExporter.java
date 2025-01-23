public class SqlExporter {

    public static void main(String[] args) {
        SqlExporter exporter = new SqlExporter();
        String sql = exporter.generateSql();
        exporter.exportToFile(sql);
    }

    public String generateSql() {
        // Example SQL generation logic
        StringBuilder sqlBuilder = new StringBuilder();
        sqlBuilder.append("CREATE TABLE books (\n");
        sqlBuilder.append("    BookID INT PRIMARY KEY,\n");
        sqlBuilder.append("    Title VARCHAR(100),\n");
        sqlBuilder.append("    Author VARCHAR(100),\n");
        sqlBuilder.append("    Genre VARCHAR(50),\n");
        sqlBuilder.append("    Price DECIMAL(10, 2)\n");
        sqlBuilder.append(");\n");
        return sqlBuilder.toString();
    }

    public void exportToFile(String sql) {
        try (java.io.FileWriter fileWriter = new java.io.FileWriter("src/main/java/export.sql")) {
            fileWriter.write(sql);
            System.out.println("SQL exported successfully to export.sql");
        } catch (java.io.IOException e) {
            e.printStackTrace();
        }
    }
}