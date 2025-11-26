package prac15;
import java.sql.*;
import java.io.*;

public class JdbcConnection {

	 private static final String USER="jdbc:mysql://localhost:3306/student";
	 private static final String Root="root";
	 private static final String pswd="admin";
	 
	 public static void main(String args[])throws IOException,ClassNotFoundException
	 {
	 Class.forName("com.mysql.jdbc.Driver");
	 try(Connection con=DriverManager.getConnection(USER,Root,pswd))
	 {
	  System.out.println("Connected Successfully");
	  
	 }catch(Exception e)
	 {
	  e.printStackTrace();
	 }
	}
	}
