
#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary search tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        // If the tree is empty, create a new node as the root
        return createNode(data);
    }

    // Otherwise, insert the node in the appropriate subtree
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to calculate the height of the binary tree
int calculateHeight(Node* root) {
    if (root == NULL) {
        // Height of an empty tree is -1
        return -1;
    }

    // Recursively calculate the height of left and right subtrees
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);

    // The height of the current node is 1 plus the maximum height of its subtrees
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Function to free the memory allocated for the binary tree
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\nBinary Search Tree Menu:\n");
        printf("1. Insert a node\n");
        printf("2. Calculate tree height\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter node value to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                printf("Node inserted successfully.\n");
                break;
            case 2:
                {
                    int height = calculateHeight(root);
                    printf("The height of the tree is: %d\n", height);
                }
                break;
            case 3:
                // Free allocated memory and exit
                freeTree(root);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
