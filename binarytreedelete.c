#include <stdio.h>
#include <stdlib.h>

// Definition of a binary search tree (BST) node
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

// Function to find the minimum value node in a given tree
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the binary search tree
Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        // Node to be deleted not found
        return root;
    }

    if (data < root->data) {
        // Node to be deleted is in the left subtree
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        // Node to be deleted is in the right subtree
        root->right = deleteNode(root->right, data);
    } else {
        // Node to be deleted is found
        if (root->left == NULL) {
            // Node has only right child or no children
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            // Node has only left child
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node has two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function for in-order traversal of the binary search tree
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to free the memory allocated for the binary search tree
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
        printf("2. Delete a node\n");
        printf("3. Display in-order traversal\n");
        printf("4. Exit\n");
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
                printf("Enter node value to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Node deleted successfully.\n");
                break;
            case 3:
                printf("In-order traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 4:
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