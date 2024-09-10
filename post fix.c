#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define a structure for the expression tree nodes
typedef struct Node {
    char data;
    struct Node *left;
    struct Node *right;
} Node;

// Function prototypes
Node* createNode(char data);
Node* constructTree(char* postfix);
int evaluate(Node* root);
void inorderTraversal(Node* root);

int main() {
    char postfix[] = "ab+cde+**";  // Example postfix expression

    Node* root = constructTree(postfix);

    printf("Inorder Traversal of the Expression Tree: ");
    inorderTraversal(root);
    printf("\n");

    int result = evaluate(root);
    printf("Evaluation Result: %d\n", result);

    return 0;
}

// Function to create a new node
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to construct the expression tree from postfix expression
Node* constructTree(char* postfix) {
    Node* stack[100];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        
        if (isalnum(ch)) {  // If the character is an operand
            Node* node = createNode(ch);
            stack[++top] = node;
        } else {  // The character is an operator
            Node* node = createNode(ch);
            node->right = stack[top--];
            node->left = stack[top--];
            stack[++top] = node;
        }
    }

    return stack[top];
}

// Function to evaluate the expression tree
int evaluate(Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return root->data - '0';  // Convert character digit to integer

    int leftEval = evaluate(root->left);
    int rightEval = evaluate(root->right);

    switch (root->data) {
        case '+': return leftEval + rightEval;
        case '-': return leftEval - rightEval;
        case '*': return leftEval * rightEval;
        case '/': return leftEval / rightEval;
        default: return 0;
    }
}

// Function to perform inorder traversal of the tree
void inorderTraversal(Node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%c ", root->data);
    inorderTraversal(root->right);
}