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

NODE findMax(NODE root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

NODE deleteNode(NODE root, int data) {
    if (root == NULL) return root;
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            NODE temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            NODE temp = root->left;
            free(root);
            return temp;
        } else {
            NODE maxNode = findMax(root->left);
            root->data = maxNode->data;
            root->left = deleteNode(root->left, maxNode->data);
        }
    }
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
    NODE root = NULL;
    int choice, data;
    printf("\nMenu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. In-order Traversal\n");
        printf("4. Exit\n");
    do {
        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insert(&root, data);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                printf("In-order Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

/*
output:
Menu:
1. Insert an element
2. Delete an element
3. In-order Traversal
4. Exit
> 1
Enter the element to insert: 5
> 1
Enter the element to insert: 2
> 1
Enter the element to insert: 7
> 3
In-order Traversal: 2 5 7 
> 2
Enter the element to delete: 5
> 3
In-order Traversal: 2 7 
> 4
Exiting...
*/