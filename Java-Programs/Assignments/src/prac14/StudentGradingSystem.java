package prac14;
import java.util.*;

class Student {
    String name;
    int rollNo;
    
    Student(String name, int rollNo) {
        this.name = name;
        this.rollNo = rollNo;
    }
}

class AcademicRecord extends Student {
    int[] marks;
    int total;
    double percentage;
    char grade;
    
    AcademicRecord(String name, int rollNo, int[] marks) {
        super(name, rollNo);
        this.marks = marks;
        calculateResults();
    }
    
    void calculateResults() {
        total = 0;
        for (int mark : marks) {
            total += mark;
        }
        percentage = total / 5.0;
        
        if (percentage >= 90) grade = 'A';
        else if (percentage >= 80) grade = 'B';
        else if (percentage >= 70) grade = 'C';
        else if (percentage >= 60) grade = 'D';
        else if (percentage >= 40) grade = 'E';
        else grade = 'F';
    }
    
    void displayResult() {
        System.out.printf("%-10d %-15s %-5d %-5d %-5d %-5d %-5d %-5d %-8.2f %-5c\n", 
                         rollNo, name, marks[0], marks[1], marks[2], marks[3], marks[4], total, percentage, grade);
    }
}

public class StudentGradingSystem {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter number of students: ");
        int n = scanner.nextInt();
        scanner.nextLine();
        
        AcademicRecord[] students = new AcademicRecord[n];
        
        for (int i = 0; i < n; i++) {
            System.out.println("\nEnter details for Student " + (i + 1) + ":");
            System.out.print("Name: ");
            String name = scanner.nextLine();
            System.out.print("Roll No: ");
            int rollNo = scanner.nextInt();
            
            int[] marks = new int[5];
            System.out.println("Enter marks for 5 subjects:");
            for (int j = 0; j < 5; j++) {
                System.out.print("Subject " + (j + 1) + ": ");
                marks[j] = scanner.nextInt();
            }
            scanner.nextLine();
            
            students[i] = new AcademicRecord(name, rollNo, marks);
        }
        
        System.out.println("\n\nStudent Results:");
        System.out.println("-----------------------------------------------------------------------------");
        System.out.printf("%-10s %-15s %-5s %-5s %-5s %-5s %-5s %-5s %-8s %-5s\n", 
                         "Roll No", "Name", "Sub1", "Sub2", "Sub3", "Sub4", "Sub5", "Total", "Percent", "Grade");
        System.out.println("-----------------------------------------------------------------------------");
        
        for (AcademicRecord student : students) {
            student.displayResult();
        }
        
        System.out.println("-----------------------------------------------------------------------------");
        scanner.close();
    }
}
