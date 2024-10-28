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

typedef struct QueueNode {
    NODE treeNode;
    struct QueueNode* next;
} *QUEUENODE;

typedef struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
} *QUEUE;

QUEUE createQueue() {
    QUEUE q = (QUEUE)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(QUEUE q) {
    return q->front == NULL;
}

void enqueue(QUEUE q, NODE node) {
    QUEUENODE temp = (QUEUENODE)malloc(sizeof(struct QueueNode));
    temp->treeNode = node;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

NODE dequeue(QUEUE q) {
    if (isEmpty(q)) return NULL;
    QUEUENODE temp = q->front;
    NODE node = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return node;
}

void levelOrderTraversal(NODE root) {
    if (root == NULL) return;
    QUEUE q = createQueue();
    enqueue(q, root);
    while (!isEmpty(q)) {
        NODE current = dequeue(q);
        printf("%d ", current->data);
        if (current->left != NULL) {
            enqueue(q, current->left);
        }
        if (current->right != NULL) {
            enqueue(q, current->right);
        }
    }
    free(q);
}

void freeTree(NODE root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

NODE buildTree() {
    int data;
    printf("Enter the root value: ");
    scanf("%d", &data);
    if (data == -1) return NULL;

    NODE root = createNode(data);
    QUEUE q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        NODE current = dequeue(q);

        printf("Enter left child of %d (-1 for no child): ", current->data);
        scanf("%d", &data);
        if (data != -1) {
            current->left = createNode(data);
            enqueue(q, current->left);
        }

        printf("Enter right child of %d (-1 for no child): ", current->data);
        scanf("%d", &data);
        if (data != -1) {
            current->right = createNode(data);
            enqueue(q, current->right);
        }
    }
    free(q);
    return root;
}

int main() {
    NODE root = buildTree();
    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("\n");
    freeTree(root);
    return 0;
}

/*
output:
Enter the root value: 1
Enter left child of 1 (-1 for no child): 2
Enter right child of 1 (-1 for no child): 3
Enter left child of 2 (-1 for no child): -1
Enter right child of 2 (-1 for no child): -1
Enter left child of 3 (-1 for no child): -1
Enter right child of 3 (-1 for no child): -1
Level Order Traversal: 1 2 3
*/