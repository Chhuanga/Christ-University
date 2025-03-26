//EmployeeStruct
#include <stdio.h>
#include <stdlib.h>

struct Employee{
    int id;
    char name[50];
    float salary;
};

int main(){
    struct Employee emp1[3];

    for(int i=0;i<3;i++){
        printf("Enter Employee ID: ");
        scanf("%d", &emp1[i].id);
        printf("Enter Employee Name: ");
        scanf("%49s", emp1[i].name);
        printf("Enter Employee Salary: ");
        scanf("%f", &emp1[i].salary);
    }
    
    int highestSalaryIndex=0;
    for(int i=1;i<3;i++){
        if(emp1[i].salary>emp1[highestSalaryIndex].salary){
            highestSalaryIndex=i;
        }
    }
    printf("\nDetails of the employee with highest salary:\n");
    printf("ID: %d\n", emp1[highestSalaryIndex].id);
    printf("Name: %s\n", emp1[highestSalaryIndex].name);
    printf("Salary: %.2f\n", emp1[highestSalaryIndex].salary);

    return 0;
}
