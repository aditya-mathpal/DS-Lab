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

void insert(NODE *root, int data) {
    NODE newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }
    NODE current = *root;
    NODE parent = NULL;
    while (current != NULL) {
        parent = current;
        if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }
    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

NODE findMin(NODE root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

NODE findSuccessor(NODE root, int data) {
    NODE current = root;
    NODE successor = NULL;
    while (current != NULL) {
        if (data < current->data) {
            successor = current;
            current = current->left;
        } else if (data > current->data) {
            current = current->right;
        } else {
            break;
        }
    }
    if (current != NULL && current->right != NULL) {
        return findMin(current->right);
    }
    return successor;
}

void inorderTraversal(NODE root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    NODE root = NULL;
    int data;
    printf("Enter numbers to insert into the BST (enter -1 to stop):\n");
    while (1) {
        printf("> ");
        scanf("%d", &data);
        if (data == -1) break;
        insert(&root, data);
    }
    printf("In-order Traversal: ");
    inorderTraversal(root);
    printf("\n");
    printf("Enter a value to find its in-order successor: ");
    scanf("%d", &data);
    NODE successor = findSuccessor(root, data);
    if (successor) {
        printf("In-order Successor of %d is %d\n", data, successor->data);
    } else {
        printf("No in-order successor found for %d\n", data);
    }
    return 0;
}

/*
output:
Enter numbers to insert into the BST (enter -1 to stop):
> 20
> 15
> 188
> -1
In-order Traversal: 15 20 188 
Enter a value to find its in-order successor: 20
In-order Successor of 20 is 188
*/  