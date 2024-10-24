#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Transaction {
    int id;
    char description[100];
    float amount;
    struct Transaction *next;
};

void insertTransaction(struct Transaction **head, int id, char *description, float amount);
void insertTransactionAtEnd(struct Transaction **head, int id, char *description, float amount);
void deleteTransaction(struct Transaction **head, int id);
void traverseTransactions(struct Transaction *head);
struct Transaction* searchTransaction(struct Transaction *head, int id);
void displayMenu();
void handleUserInput(struct Transaction **head);

int main() {
    struct Transaction *head = NULL;
    handleUserInput(&head);
    return 0;
}

void insertTransaction(struct Transaction **head, int id, char *description, float amount) {
    struct Transaction *newTransaction = (struct Transaction*)malloc(sizeof(struct Transaction));
    newTransaction->id = id;
    strcpy(newTransaction->description, description);
    newTransaction->amount = amount;
    newTransaction->next = *head;
    *head = newTransaction;
}

void insertTransactionAtEnd(struct Transaction **head, int id, char *description, float amount) {
    struct Transaction *newTransaction = (struct Transaction*)malloc(sizeof(struct Transaction));
    newTransaction->id = id;
    strcpy(newTransaction->description, description);
    newTransaction->amount = amount;
    newTransaction->next = NULL;

    if (*head == NULL) {
        *head = newTransaction;
        return;
    }

    struct Transaction *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newTransaction;
}

void deleteTransaction(struct Transaction **head, int id) {
    struct Transaction *temp = *head, *prev = NULL;
    if (temp != NULL && temp->id == id) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void traverseTransactions(struct Transaction *head) {
    struct Transaction *current = head;
    while (current != NULL) {
        printf("ID: %d, Description: %s, Amount: %.2f\n", current->id, current->description, current->amount);
        current = current->next;
    }
}

struct Transaction* searchTransaction(struct Transaction *head, int id) {
    struct Transaction *current = head;
    while (current != NULL) {
        if (current->id == id) return current;
        current = current->next;
    }
    return NULL;
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

void handleUserInput(struct Transaction **head) {
    int choice, id;
    char description[100];
    float amount;
    struct Transaction *result;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Description: ");
                scanf(" %[^\n]", description);
                printf("Enter Amount: ");
                scanf("%f", &amount);
                insertTransaction(head, id, description, amount);
                break;
            case 2:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Description: ");
                scanf(" %[^\n]", description);
                printf("Enter Amount: ");
                scanf("%f", &amount);
                insertTransactionAtEnd(head, id, description, amount);
                break;
            case 3:
                printf("Enter ID: ");
                scanf("%d", &id);
                deleteTransaction(head, id);
                break;
            case 4:
                traverseTransactions(*head);
                break;
            case 5:
                printf("Enter ID: ");
                scanf("%d", &id);
                result = searchTransaction(*head, id);
                if (result != NULL) {
                    printf("ID: %d, Description: %s, Amount: %.2f\n", result->id, result->description, result->amount);
                } else {
                    printf("Transaction not found\n");
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}