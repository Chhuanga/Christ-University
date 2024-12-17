#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(int key)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
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
        return root;

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
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

int height(struct TreeNode *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}

void inorderTraversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);
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
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            root = deleteNode(root, key);
            break;
        case 3:
            printf("Enter key to search: ");
            scanf("%d", &key);
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
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}