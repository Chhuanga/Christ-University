#include <stdio.h>

int main{

    struct Employee emp[5];
    printf("Enter Employee Details: \n");
    for(int i=0; i<5; i++){
        printf("Enter Employee Name: ");
        scanf("%49s", emp[i].name);
        printf("Enter Employee ID: ");
        scanf("%d", &emp[i].id);
        printf("Enter Employee Salary: ");
        scanf("%f", &emp[i].salary);
        printf("-----------------------------\n");
    }
    printf()