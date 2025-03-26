//Defining the accounts Interface
interface AccountActions {
    void login();
    void logout();
    void updateProfile(String name, String email);
}

class UserAccount implements AccountActions {
    protected String accountId;
    protected String name;
    protected String email;

    public UserAccount(String accountId, String name, String email) {
        this.accountId = accountId;
        this.name = name;
        this.email = email;
    }

    @Override
    public void login() {
        System.out.println(name + " logged in.");
    }

    @Override
    public void logout() {
        System.out.println(name + " logged out.");
    }

    @Override
    public void updateProfile(String name, String email) {
        this.name = name;
        this.email = email;
        System.out.println("Profile updated to Name: " + name + ", Email: " + email);
    }
}

// TeacherAccount class extending UserAccount
class TeacherAccount extends UserAccount {
    public TeacherAccount(String accountId, String name, String email) {
        super(accountId, name, email);
    }

    public void createCourse(String courseName) {
        System.out.println(name + " created a course: " + courseName);
    }

    public void manageCourse(String courseName) {
        System.out.println(name + " is managing the course: " + courseName);
    }
}

// StudentAccount class extending UserAccount
class StudentAccount extends UserAccount {
    public StudentAccount(String accountId, String name, String email) {
        super(accountId, name, email);
    }

    public void enrollInCourse(String courseName) {
        System.out.println(name + " enrolled in the course: " + courseName);
    }

    public void submitAssignment(String assignmentName) {
        System.out.println(name + " submitted the assignment: " + assignmentName);
    }
}


public class GoogleClassroom {
    public static void main(String[] args) {
        //Creating  a TeacherAccount
        TeacherAccount teacher = new TeacherAccount("T001", "Mr. Raj", "raj@gmail.com");
        teacher.login();
        teacher.createCourse("Math 101");
        teacher.manageCourse("Math 101");
        teacher.updateProfile("Mr. Raj Kumar", "rajkumar@gmail.com");
        teacher.logout();

        // Creating  a StudentAccount
        StudentAccount student = new StudentAccount("S001", "Shrey", "shrey@gmail.com");
        student.login();
        student.enrollInCourse("Math 101");
        student.submitAssignment("Math Homework 1");
        student.updateProfile("Shrey Jain", "shreyjain@gmail.com");
        student.logout();
    }
}