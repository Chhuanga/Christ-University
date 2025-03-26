#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct TreeNode
{
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(int key)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode *insert(struct TreeNode *node, int key)
{
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        printf("Key %d already exists in the tree. Duplicate keys are not allowed.\n", key);

    return node;
}

struct TreeNode *minValueNode(struct TreeNode *node)
{
    struct TreeNode *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct TreeNode *deleteNode(struct TreeNode *root, int key)
{
    if (root == NULL)
    {
        printf("Key %d not found in the tree.\n", key);
        return root;
    }

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

struct TreeNode *search(struct TreeNode *root, int key)
{
    if (root == NULL)
        return NULL;

    if (key == root->key)
        return root;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

int height(struct TreeNode *node)
{
    if (node == NULL)
        return 0;

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

void inorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
    {
        printf("The tree is empty.\n");
        return;
    }
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
    {
        printf("The tree is empty.\n");
        return;
    }
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
    {
        printf("The tree is empty.\n");
        return;
    }
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);
    }
}

int getValidatedInteger(const char *prompt)
{
    int key;
    char buffer[100];

    while (1)
    {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            char *newline = strchr(buffer, '\n');
            if (newline)
                *newline = '\0';

            char *endptr;
            key = strtol(buffer, &endptr, 10);

            if (endptr != buffer && *endptr == '\0')
                return key;

            printf("Invalid input! Please enter a valid integer.\n");
        }
        else
        {
            printf("Error reading input! Please try again.\n");
            clearerr(stdin);
        }
    }
}

void freeTree(struct TreeNode *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main()
{
    struct TreeNode *root = NULL;
    int choice, key;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Calculate Height\n");
        printf("5. Inorder Traversal\n");
        printf("6. Preorder Traversal\n");
        printf("7. Postorder Traversal\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a valid choice.\n");
            while (getchar() != '\n')
                ; // Clear input buffer
            continue;
        }

        getchar(); // Consume the newline character left by scanf

        switch (choice)
        {
        case 1:
            key = getValidatedInteger("Enter key to insert: ");
            root = insert(root, key);
            break;
        case 2:
            key = getValidatedInteger("Enter key to delete: ");
            root = deleteNode(root, key);
            break;
        case 3:
            key = getValidatedInteger("Enter key to search: ");
            struct TreeNode *result = search(root, key);
            if (result != NULL)
                printf("Key %d found in the tree.\n", key);
            else
                printf("Key %d not found in the tree.\n", key);
            break;
        case 4:
            printf("Height of the tree: %d\n", height(root));
            break;
        case 5:
            printf("Inorder traversal: ");
            inorderTraversal(root);
            printf("\n");
            break;
        case 6:
            printf("Preorder traversal: ");
            preorderTraversal(root);
            printf("\n");
            break;
        case 7:
            printf("Postorder traversal: ");
            postorderTraversal(root);
            printf("\n");
            break;
        case 8:
            freeTree(root);
            printf("Exiting program.\n");
            exit(EXIT_SUCCESS);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}