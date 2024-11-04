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

NODE insertNode() {
    int data;
    scanf("%d", &data);
    if (data == -1) {
        return NULL;
    }
    NODE newNode = createNode(data);
    newNode->left = insertNode();
    newNode->right = insertNode();
    return newNode;
}

int printAncestors(NODE root, int key) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == key) {
        return 1;
    }
    if (printAncestors(root->left, key) || printAncestors(root->right, key)) {
        printf("%d ", root->data);
        return 1;
    }
    return 0;
}

int main() {
    printf("Enter binary tree nodes in pre-order (use -1 for NULL):\n");
    NODE root = insertNode();
    int key;
    printf("Enter key to find its ancestors: ");
    scanf("%d", &key);
    printf("Ancestors of %d: ", key);
    if (!printAncestors(root, key)) {
        printf("Key not found in the tree.\n");
    }
    printf("\n");
    return 0;
}

/*
output:
Enter binary tree nodes in pre-order (use -1 for NULL):
7 6 5 4 -1 -1 -1 -1 -1
Enter key to find its ancestors: 4
Ancestors of 4: 5 6 7
*/