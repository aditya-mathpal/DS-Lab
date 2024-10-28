#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} *NODE;

NODE createNode(int data) {
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void freeTree(NODE root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

NODE copyTree(NODE root) {
    if (root == NULL) return NULL;
    NODE newRoot = createNode(root->data);
    newRoot->left = copyTree(root->left);
    newRoot->right = copyTree(root->right);
    return newRoot;
}

NODE buildTree() {
    int data;
    printf("> ");
    scanf("%d", &data);
    if (data == -1) return NULL;
    
    NODE newNode = createNode(data);
    printf("Building left subtree of %d:\n", data);
    newNode->left = buildTree();
    printf("Building right subtree of %d:\n", data);
    newNode->right = buildTree();
    return newNode;
}

void printTree(NODE root) {
    if (root == NULL) return;
    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

int main() {
    printf("Building the original binary tree\nEnter node value (-1 for no node)\n");
    NODE root = buildTree();
    
    NODE copiedRoot = copyTree(root);
    
    printf("Original tree (in-order): ");
    printTree(root);
    printf("\n");
    
    printf("Copied tree (in-order): ");
    printTree(copiedRoot);
    printf("\n");
    
    freeTree(root);
    freeTree(copiedRoot);
    return 0;
}

/*
output:
Building the original binary tree
Enter node value (-1 for no node)
> 1
Building left subtree of 1:
> 2
Building left subtree of 2:
> -1
Building right subtree of 2:
> -1
Building right subtree of 1:
> 3
Building left subtree of 3:
> -1
Building right subtree of 3:
> -1
Original tree (in-order): 2 1 3 
Copied tree (in-order): 2 1 3
*/