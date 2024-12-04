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
int linearSearch(struct Transaction *head, int id);
int sentinelSearch(struct Transaction *head, int id);
int binarySearch(struct Transaction *arr[], int l, int r, int id);
void bubbleSort(struct Transaction *arr[], int n, int *comparisons, int *dataTransfers);
void insertionSort(struct Transaction *arr[], int n, int *comparisons, int *dataTransfers);
void convertListToArray(struct Transaction *head, struct Transaction *arr[], int n);

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
    printf("5. Search Transaction (Linear Search)\n");
    printf("6. Search Transaction (Sentinel Search)\n");
    printf("7. Search Transaction (Binary Search)\n");
    printf("8. Sort Transactions (Bubble Sort)\n");
    printf("9. Sort Transactions (Insertion Sort)\n");
    printf("10. Exit\n");
    printf("Enter your choice: ");
}

void handleUserInput(struct Transaction **head) {
    int choice, id, n = 0, comparisons = 0, dataTransfers = 0;
    char description[100];
    float amount;
    struct Transaction *result;
    struct Transaction *arr[100];

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
                int index = linearSearch(*head, id);
                if (index != -1) {
                    printf("Transaction found at index %d\n", index);
                } else {
                    printf("Transaction not found\n");
                }
                break;
            case 6:
                printf("Enter ID: ");
                scanf("%d", &id);
                index = sentinelSearch(*head, id);
                if (index != -1) {
                    printf("Transaction found at index %d\n", index);
                } else {
                    printf("Transaction not found\n");
                }
                break;
            case 7:
                printf("Enter ID: ");
                scanf("%d", &id);
                convertListToArray(*head, arr, n);
                index = binarySearch(arr, 0, n - 1, id);
                if (index != -1) {
                    printf("Transaction found at index %d\n", index);
                } else {
                    printf("Transaction not found\n");
                }
                break;
            case 8:
                convertListToArray(*head, arr, n);
                bubbleSort(arr, n, &comparisons, &dataTransfers);
                printf("Bubble Sort completed with %d comparisons and %d data transfers\n", comparisons, dataTransfers);
                break;
            case 9:
                convertListToArray(*head, arr, n);
                insertionSort(arr, n, &comparisons, &dataTransfers);
                printf("Insertion Sort completed with %d comparisons and %d data transfers\n", comparisons, dataTransfers);
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

int linearSearch(struct Transaction *head, int id) {
    struct Transaction *current = head;
    int index = 0;
    while (current != NULL) {
        if (current->id == id) return index;
        current = current->next;
        index++;
    }
    return -1;
}

int sentinelSearch(struct Transaction *head, int id) {
    struct Transaction *current = head;
    struct Transaction sentinel;
    sentinel.id = id;
    sentinel.next = NULL;

    if (head == NULL) return -1;

    struct Transaction *last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = &sentinel;

    current = head;
    int index = 0;
    while (current->id != id) {
        current = current->next;
        index++;
    }

    last->next = NULL;

    if (current == &sentinel) return -1;
    return index;
}

int binarySearch(struct Transaction *arr[], int l, int r, int id) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m]->id == id) return m;
        if (arr[m]->id < id) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

void bubbleSort(struct Transaction *arr[], int n, int *comparisons, int *dataTransfers) {
    *comparisons = 0;
    *dataTransfers = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            (*comparisons)++;
            if (arr[j]->id > arr[j + 1]->id) {
                struct Transaction *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*dataTransfers)++;
            }
        }
    }
}

void insertionSort(struct Transaction *arr[], int n, int *comparisons, int *dataTransfers) {
    *comparisons = 0;
    *dataTransfers = 0;
    for (int i = 1; i < n; i++) {
        struct Transaction *key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j]->id > key->id) {
            (*comparisons)++;
            arr[j + 1] = arr[j];
            j--;
            (*dataTransfers)++;
        }
        arr[j + 1] = key;
        (*dataTransfers)++;
    }
}

void convertListToArray(struct Transaction *head, struct Transaction *arr[], int n) {
    struct Transaction *current = head;
    n = 0;
    while (current != NULL) {
        arr[n++] = current;
        current = current->next;
    }
}