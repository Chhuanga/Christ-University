// Employee Structure

#include <stdio.h>

struct Employee {
    char name[50];
    int id;
    float salary;
};

struct Employee_details {
    struct Employee emp;
    char department[50];
    char designation[50];
    int experience;
};

int main()
{
    struct Employee_details emp1;
    printf("Enter Employee Name: ");
    scanf("%49s", emp1.emp.name);
    printf("Enter Employee ID: ");
    scanf("%d", &emp1.emp.id); 
    printf("Enter Employee Salary: ");
    scanf("%f", &emp1.emp.salary); 
    printf("Enter Employee Department: ");
    scanf("%49s", emp1.department);
    printf("Enter Employee Designation: ");
    scanf("%49s", emp1.designation);
    printf("Enter Employee Experience: ");
    scanf("%d", &emp1.experience);
    printf("-----------------------------\n");

    printf("Employee Name: %s\n", emp1.emp.name);
    printf("Employee ID: %d\n", emp1.emp.id);
    printf("Employee Salary: %.2f\n", emp1.emp.salary);
    printf("Employee Department: %s\n", emp1.department);
    printf("Employee Designation: %s\n", emp1.designation);
    printf("Employee Experience: %d\n", emp1.experience);
    printf("-----------------------------\n");

    return 0;
}