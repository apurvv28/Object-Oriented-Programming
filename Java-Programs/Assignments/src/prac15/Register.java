package prac15;
import java.sql.*;
import java.util.Scanner;

public class Register {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/student"; 
        String user = "root"; 
        String password = "admin";

        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection connection = DriverManager.getConnection(url, user, password);

            if (connection != null) {
                System.out.println("Connected to the database!");
                
                String createTableSQL = "CREATE TABLE IF NOT EXISTS students (id VARCHAR(50) PRIMARY KEY, name VARCHAR(100), email VARCHAR(100), password VARCHAR(100))";
                Statement stmt = connection.createStatement();
                stmt.executeUpdate(createTableSQL);
                System.out.println("Table 'students' is ready.");
                
                Scanner scanner = new Scanner(System.in);
                System.out.print("Enter ID: ");
                String id = scanner.nextLine();
                System.out.print("Enter Name: ");
                String name = scanner.nextLine();
                System.out.print("Enter Email: ");
                String email = scanner.nextLine();
                System.out.print("Enter Password: ");
                String pass = scanner.nextLine();
                
                String insertSQL = "INSERT INTO students (id, name, email, password) VALUES (?, ?, ?, ?)";
                PreparedStatement pstmt = connection.prepareStatement(insertSQL);
                pstmt.setString(1, id);
                pstmt.setString(2, name);
                pstmt.setString(3, email);
                pstmt.setString(4, pass);
                pstmt.executeUpdate();
                
                System.out.println("Data inserted successfully!");
                
                scanner.close();
                stmt.close();
                pstmt.close();
                connection.close();
            }
        } catch (ClassNotFoundException e) {
            System.out.println("MySQL JDBC Driver not found!");
            e.printStackTrace();
        } catch (SQLException e) {
            System.out.println("Connection failed!");
            e.printStackTrace();
        }
    }
}