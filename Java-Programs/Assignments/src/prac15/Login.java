package prac15;
import java.sql.*;
import java.util.Scanner;

public class Login {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/student"; 
        String user = "root"; 
        String password = "admin";

        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection connection = DriverManager.getConnection(url, user, password);

            if (connection != null) {
                System.out.println("Connected to the database!");

                Scanner scanner = new Scanner(System.in);
                System.out.print("Enter ID: ");
                String id = scanner.nextLine();
                System.out.print("Enter Password: ");
                String pass = scanner.nextLine();

                String loginSQL = "SELECT * FROM students WHERE id = ? AND password = ?";
                PreparedStatement pstmt = connection.prepareStatement(loginSQL);
                pstmt.setString(1, id);
                pstmt.setString(2, pass);

                ResultSet resultSet = pstmt.executeQuery();

                if (resultSet.next()) {
                    String name = resultSet.getString("name");
                    String email = resultSet.getString("email");
                    System.out.println("Logged in successfully!");
                    System.out.println("Welcome, " + name + "!");
                    System.out.println("Email: " + email);
                    System.out.println("ID: " + id);
                } else {
                    System.out.println("Invalid ID or password!");
                }

                scanner.close();
                resultSet.close();
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