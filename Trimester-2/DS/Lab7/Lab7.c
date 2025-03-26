#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the structure for a binary tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed. Exiting.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to check if a value exists in the tree
int valueExists(struct Node *root, int data)
{
    if (root == NULL)
        return 0;
    if (root->data == data)
        return 1;
    return valueExists(root->left, data) || valueExists(root->right, data);
}

// Function to insert a node at the root
struct Node *insertAtRoot(struct Node *root, int data)
{
    if (valueExists(root, data))
    {
        printf("Value %d already exists in the tree. Cannot insert duplicate values.\n", data);
        return root;
    }
    struct Node *newNode = createNode(data);
    if (root == NULL)
    {
        return newNode;
    }
    newNode->left = root;
    return newNode;
}

// Function to delete the root node
struct Node *deleteRoot(struct Node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty. Cannot delete root.\n");
        return NULL;
    }
    struct Node *temp = root;
    if (root->left == NULL)
    {
        root = root->right;
    }
    else if (root->right == NULL)
    {
        root = root->left;
    }
    else
    {
        struct Node *parent = root;
        struct Node *successor = root->right;
        while (successor->left != NULL)
        {
            parent = successor;
            successor = successor->left;
        }
        if (parent != root)
        {
            parent->left = successor->right;
            successor->right = root->right;
        }
        successor->left = root->left;
        root = successor;
    }
    free(temp);
    printf("Root deleted successfully.\n");
    return root;
}

// Preorder traversal
void preorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Inorder traversal
void inorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Level-order traversal
void levelOrderTraversal(struct Node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty.\n");
        return;
    }
    struct Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear)
    {
        struct Node *current = queue[front++];
        printf("%d ", current->data);
        if (current->left != NULL)
            queue[rear++] = current->left;
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}

// Function to safely get an integer input
int getIntInput(const char *prompt)
{
    int value;
    char buffer[100];
    char *endptr;

    while (1)
    {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            printf("Error reading input. Try again.\n");
            continue;
        }

        // Remove newline character if present
        buffer[strcspn(buffer, "\n")] = '\0';

        // Try to convert input to an integer
        value = strtol(buffer, &endptr, 10);
        if (*endptr == '\0')
        {
            return value; // Valid integer
        }
        else
        {
            printf("Invalid input. Please enter a valid integer.\n");
        }
    }
}

// Main function to demonstrate the functionalities
int main()
{
    struct Node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\n===================================\n");
        printf("      Binary Tree Operations       \n");
        printf("===================================\n");
        printf("1. Insert at Root\n");
        printf("2. Delete Root\n");
        printf("3. Preorder Traversal\n");
        printf("4. Inorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Level-order Traversal\n");
        printf("7. Exit\n");
        printf("===================================\n");

        choice = getIntInput("Enter your choice: ");

        switch (choice)
        {
        case 1:
            value = getIntInput("Enter value to insert: ");
            root = insertAtRoot(root, value);
            if (!valueExists(root, value))
            {
                printf("Value %d inserted at root.\n", value);
            }
            break;
        case 2:
            root = deleteRoot(root);
            break;
        case 3:
        case 4:
        case 5:
        case 6:
            if (root == NULL)
            {
                printf("Tree is empty. Cannot perform traversal.\n");
            }
            else
            {
                switch (choice)
                {
                case 3:
                    printf("Preorder Traversal: ");
                    preorderTraversal(root);
                    break;
                case 4:
                    printf("Inorder Traversal: ");
                    inorderTraversal(root);
                    break;
                case 5:
                    printf("Postorder Traversal: ");
                    postorderTraversal(root);
                    break;
                case 6:
                    printf("Level-order Traversal: ");
                    levelOrderTraversal(root);
                    break;
                }
                printf("\n");
            }
            break;
        case 7:
            printf("Exiting program. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice! Please enter a number between 1 and 7.\n");
        }
    }

    return 0;
}
