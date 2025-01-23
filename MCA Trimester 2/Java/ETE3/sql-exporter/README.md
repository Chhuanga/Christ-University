# SQL Exporter

This project is a simple Java application that generates SQL statements and exports them to an SQL file.

## Project Structure

```
sql-exporter
├── src
│   ├── main
│   │   ├── java
│   │   │   └── com
│   │   │       └── example
│   │   │           └── SqlExporter.java
│   │   └── resources
│   │       └── export.sql
├── .gitignore
├── build.gradle
└── README.md
```

## Features

- Generate SQL commands programmatically.
- Export generated SQL commands to `export.sql`.

## Getting Started

### Prerequisites

- Java Development Kit (JDK) 8 or higher
- Gradle

### Building the Project

1. Clone the repository:
   ```
   git clone <repository-url>
   ```
2. Navigate to the project directory:
   ```
   cd sql-exporter
   ```
3. Build the project using Gradle:
   ```
   ./gradlew build
   ```

### Running the Application

To run the application, execute the following command:
```
java -cp build/libs/sql-exporter.jar com.example.SqlExporter
```

### Exported SQL File

The generated SQL commands will be saved in the `src/main/resources/export.sql` file. You can open this file to view the exported SQL statements.

## License

This project is licensed under the MIT License. See the LICENSE file for details.