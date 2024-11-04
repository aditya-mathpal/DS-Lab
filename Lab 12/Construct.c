#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

NODE constructTree(int* preorder, int* postorder, int* preIndex, int left, int right, int size) {
    if (*preIndex >= size || left > right) {
        return NULL;
    }
    
    NODE root = createNode(preorder[*preIndex]);
    (*preIndex)++;

    if (left == right || *preIndex >= size) {
        return root;
    }

    int postIndex = left;
    while (postorder[postIndex] != preorder[*preIndex] && postIndex <= right) {
        postIndex++;
    }

    root->left = constructTree(preorder, postorder, preIndex, left, postIndex, size);
    root->right = constructTree(preorder, postorder, preIndex, postIndex + 1, right - 1, size);
    
    return root;
}

void inorderTraversal(NODE root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    int size;

    printf("Enter the number of nodes: ");
    scanf("%d", &size);

    int *preorder = malloc(size * sizeof(int));
    int *postorder = malloc(size * sizeof(int));

    printf("Enter the pre-order traversal: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &preorder[i]);
    }

    printf("Enter the post-order traversal: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &postorder[i]);
    }

    int preIndex = 0;
    NODE root = constructTree(preorder, postorder, &preIndex, 0, size - 1, size);

    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    free(preorder);
    free(postorder);
    return 0;
}

/*
output:
Enter the number of nodes: 3
Enter the pre-order traversal: 1 2 3
Enter the post-order traversal: 2 3 1
In-order traversal: 2 1 3
*/