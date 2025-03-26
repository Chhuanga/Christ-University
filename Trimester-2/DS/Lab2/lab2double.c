#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Transaction {
    int id;
    char description[100];
    float amount;
    struct Transaction *next;
    struct Transaction *prev;
};

void insertTransaction(struct Transaction **head, int id, char *description, float amount);
void deleteTransaction(struct Transaction **head, int id);
void traverseTransactions(struct Transaction *head);
void searchTransaction(struct Transaction *head, int id);
void displayMenu();
void handleUserInput(struct Transaction **head);
int validateIntInput(int *value);
int validateFloatInput(float *value);

void insertTransaction(struct Transaction **head, int id, char *description, float amount) {
    struct Transaction *newTransaction = (struct Transaction*)malloc(sizeof(struct Transaction));
    newTransaction->id = id;
    strcpy(newTransaction->description, description);
    newTransaction->amount = amount;
    newTransaction->next = *head;
    newTransaction->prev = NULL;
    if (*head != NULL) {
        (*head)->prev = newTransaction;
    }
    *head = newTransaction;
}

void deleteTransaction(struct Transaction **head, int id) {
    struct Transaction *temp = *head;
    while (temp != NULL && temp->id != id) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Transaction not found\n");
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp == *head) {
        *head = temp->next;
    }
    free(temp);
}

void traverseTransactions(struct Transaction *head) {
    struct Transaction *current = head;
    while (current != NULL) {
        printf("ID: %d, Description: %s, Amount: %.2f\n", current->id, current->description, current->amount);
        current = current->next;
    }
}

void searchTransaction(struct Transaction *head, int id) {
    struct Transaction *current = head;
    while (current != NULL) {
        if (current->id == id) {
            printf("ID: %d, Description: %s, Amount: %.2f\n", current->id, current->description, current->amount);
            return;
        }
        current = current->next;
    }
    printf("Transaction not found\n");
}

void displayMenu() {
    printf("Finance Management System\n");
    printf("1. Insert Transaction at Beginning\n");
    printf("2. Insert Transaction at End\n");
    printf("3. Delete Transaction\n");
    printf("4. View All Transactions\n");
    printf("5. Search Transaction\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int validateIntInput(int *value) {
    if (scanf("%d", value) != 1) {
        while (getchar() != '\n'); // Clear the input buffer
        return 0;
    }
    return 1;
}

int validateFloatInput(float *value) {
    if (scanf("%f", value) != 1) {
        while (getchar() != '\n'); // Clear the input buffer
        return 0;
    }
    return 1;
}

void handleUserInput(struct Transaction **head) {
    int choice, id;
    char description[100];
    float amount;

    while (1) {
        displayMenu();
        if (!validateIntInput(&choice)) {
            printf("Invalid choice. Please enter an integer.\n");
            continue;
        }
        switch (choice) {
            case 1:
                printf("Enter ID: ");
                while (!validateIntInput(&id)) {
                    printf("Invalid input. Please enter an integer.\n");
                }
                printf("Enter Description: ");
                scanf(" %[^\n]", description);
                printf("Enter Amount: ");
                while (!validateFloatInput(&amount)) {
                    printf("Invalid input. Please enter a float.\n");
                }
                insertTransaction(head, id, description, amount);
                break;
            case 2:
                printf("Enter ID: ");
                while (!validateIntInput(&id)) {
                    printf("Invalid input. Please enter an integer.\n");
                }
                printf("Enter Description: ");
                scanf(" %[^\n]", description);
                printf("Enter Amount: ");
                while (!validateFloatInput(&amount)) {
                    printf("Invalid input. Please enter a float.\n");
                }
                insertTransaction(head, id, description, amount);
                break;
            case 3:
                printf("Enter ID: ");
                while (!validateIntInput(&id)) {
                    printf("Invalid input. Please enter an integer.\n");
                }
                deleteTransaction(head, id);
                break;
            case 4:
                traverseTransactions(*head);
                break;
            case 5:
                printf("Enter ID: ");
                while (!validateIntInput(&id)) {
                    printf("Invalid input. Please enter an integer.\n");
                }
                searchTransaction(*head, id);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

int main() {
    struct Transaction *head = NULL;
    while (1) {
        handleUserInput(&head);
    }
    return 0;
}