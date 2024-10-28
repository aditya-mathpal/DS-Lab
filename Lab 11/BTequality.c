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

int testEquality(NODE a, NODE b) {
    if (a == NULL && b == NULL) return 1;
    if (a == NULL || b == NULL) return 0;
    return (a->data == b->data) && 
           testEquality(a->left, b->left) && 
           testEquality(a->right, b->right);
}

void freeTree(NODE root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    printf("Building the first binary tree\nEnter node value (-1 for no node)\n");
    NODE tree1 = buildTree();
    
    printf("Building the second binary tree\nEnter node value (-1 for no node)\n");
    NODE tree2 = buildTree();
    
    if (testEquality(tree1, tree2)) {
        printf("The two trees are equal.\n");
    } else {
        printf("The two trees are not equal.\n");
    }
    
    freeTree(tree1);
    freeTree(tree2);
    return 0;
}

/*
output:
Building the first binary tree
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
Building the second binary tree
Enter node value (-1 for no node)
> 8
Building left subtree of 8:
> -1
Building right subtree of 8:
> -1
The two trees are not equal.
*/