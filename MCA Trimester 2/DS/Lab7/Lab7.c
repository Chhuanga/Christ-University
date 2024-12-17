#include <stdio.h>
#include <stdlib.h>

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
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node at the root
struct Node *insertAtRoot(struct Node *root, int data)
{
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
        printf("Tree is empty.\n");
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
        return;
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

// Main function to demonstrate the functionalities
int main()
{
    struct Node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\n1. Insert at Root\n2. Delete Root\n3. Preorder Traversal\n4. Inorder Traversal\n5. Postorder Traversal\n6. Level-order Traversal\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insertAtRoot(root, value);
            break;
        case 2:
            root = deleteRoot(root);
            break;
        case 3:
            preorderTraversal(root);
            printf("\n");
            break;
        case 4:
            inorderTraversal(root);
            printf("\n");
            break;
        case 5:
            postorderTraversal(root);
            printf("\n");
            break;
        case 6:
            levelOrderTraversal(root);
            printf("\n");
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}