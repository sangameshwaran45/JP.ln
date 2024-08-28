#include <stdio.h>
#include <stdlib.h>

// Definition of a TreeNode
typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary tree (for testing purposes)
TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// Post-order traversal function
void postOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);     // Traverse left subtree
        postOrderTraversal(root->right);    // Traverse right subtree
        printf("%d ", root->value);         // Visit node
    }
}