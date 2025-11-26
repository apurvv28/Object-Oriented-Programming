import java.io.*;
import java.util.*;

public class Student {
    String name;
    int roll;
    int marks[];
    double percentage;
    String grade;
    Student(String n, int r, int m[]) {
        name = n;
        roll = r;
        marks = m;
        percentage = calculatePer(m);
        grade = calculateGrade(percentage);
    }
    void display() {
        System.out.println("Name : " + name);
        System.out.println("Roll No : " + roll);
        System.out.println("Percentage : " + percentage);
        System.out.println("Grade : " + grade);
    }
    double calculatePer(int m[]) {
        int sum = 0;
        for (int i = 0; i < m.length; i++) {
            sum += m[i];
        }
        percentage = (double) sum / m.length;
        return percentage;
    }
    String calculateGrade(double p) {
        if (p >= 90) return "A";
        else if (p >= 75) return "B";
        else if (p >= 60) return "C";
        else return "D";
    }
    protected void finalize(){
    	System.out.println("The space alloted to objects is destroyed!");
    }
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter name of student : ");
        String n = sc.nextLine();
        System.out.println("Enter roll no. of student : ");
        int r = sc.nextInt();
        int a = 5; 
        int m[] = new int[a];
        System.out.println("Enter marks of " + a + " subjects : ");
        for (int i = 0; i < a; i++) {
            m[i] = sc.nextInt();
        }
        Student s1 = new Student(n, r, m);
        s1.display();
        sc.close();
        System.gc();
    }
}
