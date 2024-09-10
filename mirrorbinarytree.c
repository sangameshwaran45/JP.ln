
#include <stdio.h>
#include <stdlib.h>

// Definition of the tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new tree node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to print the tree in-order
void printInOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

// Function to mirror the tree
void mirrorTree(Node* root) {
    if (root == NULL) {
        return;
    }
    
    // Swap the left and right children
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    // Recursively mirror the left and right subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);
}

// Function to free the tree nodes
void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Main function
int main() {
    // Create the binary tree
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Original tree (in-order): ");
    printInOrder(root);
    printf("\n");

    // Mirror the tree
    mirrorTree(root);

    printf("Mirrored tree (in-order): ");
    printInOrder(root);
    printf("\n");

    // Free the allocated memory
    freeTree(root);

    return 0;
}
