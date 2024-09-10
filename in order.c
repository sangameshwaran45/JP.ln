
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;


Node* createNode(int data);
Node* insert(Node* root, int data);
void inorderTraversal(Node* root);


int main() {
    Node* root = NULL;

    // Insert elements into the binary search tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print elements in sorted order using in-order traversal
    printf("In-order Traversal (Sorted Order): ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}


void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left); 
    printf("%d ", root->data); 
    inorderTraversal(root->right); 
}
