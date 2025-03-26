#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    int id;
    char name[50];
    int performanceScore;
    struct Employee *next;
};

struct Employee *head = NULL;

void insertEmployee(int id, char name[], int performanceScore)
{
    struct Employee *newEmployee = (struct Employee *)malloc(sizeof(struct Employee));
    newEmployee->id = id;
    strcpy(newEmployee->name, name);
    newEmployee->performanceScore = performanceScore;
    newEmployee->next = NULL;

    if (head == NULL)
    {
        head = newEmployee;
        newEmployee->next = head;
    }
    else
    {
        struct Employee *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newEmployee;
        newEmployee->next = head;
    }
}

// Displaying the employee details
void displayEmployee()
{
    struct Employee *temp = head;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        do
        {
            printf("Employee ID: %d\n", temp->id);
            printf("Employee Name: %s\n", temp->name);
            printf("Employee performanceScore: %d\n", temp->performanceScore);
            temp = temp->next;
        } while (temp != head);
    }
}

// Find the employee with the highest performanceScore
void highestperformanceScore()
{
    struct Employee *temp = head;
    struct Employee *high = head;

    if (head == NULL)
    {
        printf("No Employee Records to display\n");
    }
    else
    {
        do
        {
            if (temp->performanceScore > high->performanceScore)
            {
                high = temp;
            }
            temp = temp->next;
        } while (temp != head);
    }
    printf("Employee with the highest performanceScore is: %s\n", high->name);
    printf("Employee Score: %d\n", high->performanceScore);
}

// Split employees based on performance score
void splitEmployeesByPerformance()
{
    struct Employee *temp = head;
    if (head == NULL)
    {
        printf("No Employee Records to display\n");
        return;
    }

    printf("Low Performance Employees (Score < 40):\n");
    do
    {
        if (temp->performanceScore < 40)
        {
            printf("Employee ID: %d\n", temp->id);
            printf("Employee Name: %s\n", temp->name);
            printf("Employee performanceScore: %d\n", temp->performanceScore);
        }
        temp = temp->next;
    } while (temp != head);

    temp = head;
    printf("\nHigh Performance Employees (Score >= 40):\n");
    do
    {
        if (temp->performanceScore >= 40)
        {
            printf("Employee ID: %d\n", temp->id);
            printf("Employee Name: %s\n", temp->name);
            printf("Employee performanceScore: %d\n", temp->performanceScore);
        }
        temp = temp->next;
    } while (temp != head);
}

int main()
{
    int choice, id, performanceScore;
    char name[50];

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert Employee\n");
        printf("2. Display Employees\n");
        printf("3. Find Employee with Highest Performance Score\n");
        printf("4. Split Employees by Performance Score\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Employee ID: ");
            scanf("%d", &id);
            if (id < 0)
            {
                printf("ID cannot be negative. Try again.\n");
                break;
            }
            printf("Enter Employee Name: ");
            scanf("%s", name);
            printf("Enter Employee Performance Score (0-100): ");
            scanf("%d", &performanceScore);
            if (performanceScore < 0 || performanceScore > 100)
            {
                printf("Performance Score must be between 0 and 100. Try again.\n");
                break;
            }
            insertEmployee(id, name, performanceScore);
            break;  
        case 2:
            displayEmployee();
            break;
        case 3:
            highestperformanceScore();
            break;
        case 4:
            splitEmployeesByPerformance();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
