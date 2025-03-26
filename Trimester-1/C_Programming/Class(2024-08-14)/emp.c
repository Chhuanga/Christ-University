// Employee Structure

#include <stdio.h>

struct Employee {
    char name[50];
    int id;
    float salary;
};

int main() {
    struct Employee emp1;
    printf("Enter Employee Name: ");
    scanf("%49s", emp1.name);  
    printf("Enter Employee ID: ");
    scanf("%d", &emp1.id);
    printf("Enter Employee Salary: ");
    scanf("%f", &emp1.salary);
    printf("-----------------------------\n");
    printf("Employee Name: %s\n", emp1.name);
    printf("Employee ID: %d\n", emp1.id);
    printf("Employee Salary: %.2f\n", emp1.salary);
    printf("-----------------------------\n");
    return 0;
}