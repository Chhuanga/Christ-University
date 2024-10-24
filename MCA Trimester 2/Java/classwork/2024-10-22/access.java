public class Student {
    private String name;  
    private int grade;   
    
    public Student() {
        this.name = "Unknown";
        this.grade = 0;
        System.out.println("Default Constructor called");
    }
    
    public Student(String name, int grade) {
        this.name = name;
        this.grade = grade;
        displayDetails();
        displayGrades();
    }
    
    public void displayDetails() {
        System.out.println("Student Name: " + this.name);
    }
    
    public void displayGrades() {
        System.out.println("Student Grades: " + this.grade);
    }
}

public class Main {
    public static void main(String[] args) {
        Student student1 = new Student("Alice", 90);
        
        System.out.println("Accessing name directly: " + student1.name);  
        System.out.println("Accessing grade directly: " + student1.grade);  

        student1.displayDetails();  
        student1.displayGrades();   
    }
}
