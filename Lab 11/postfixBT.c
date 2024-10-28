#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} *NODE;

typedef struct StackNode {
    NODE treeNode;
    struct StackNode* next;
} *STACKNODE;

typedef struct Stack {
    STACKNODE top;
} *STACK;

NODE createNode(char data) {
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

STACK createStack() {
    STACK stack = (STACK)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(STACK stack) {
    return stack->top == NULL;
}

void push(STACK stack, NODE node) {
    STACKNODE newStackNode = (STACKNODE)malloc(sizeof(struct StackNode));
    newStackNode->treeNode = node;
    newStackNode->next = stack->top;
    stack->top = newStackNode;
}

NODE pop(STACK stack) {
    if (isEmpty(stack)) return NULL;
    STACKNODE temp = stack->top;
    NODE node = temp->treeNode;
    stack->top = stack->top->next;
    free(temp);
    return node;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

NODE buildExpressionTree(char* postfix) {
    STACK stack = createStack();
    for (int i = 0; postfix[i]; i++) {
        char token = postfix[i];
        NODE newNode = createNode(token);
        if (isOperator(token)) {
            newNode->right = pop(stack);
            newNode->left = pop(stack);
        }
        push(stack, newNode);
    }
    NODE root = pop(stack);
    free(stack);
    return root;
}

int evaluateExpressionTree(NODE root) {
    if (root == NULL) return 0;
    if (!isOperator(root->data)) return root->data - '0';

    int leftEval = evaluateExpressionTree(root->left);
    int rightEval = evaluateExpressionTree(root->right);

    switch (root->data) {
        case '+': return leftEval + rightEval;
        case '-': return leftEval - rightEval;
        case '*': return leftEval * rightEval;
        case '/': return leftEval / rightEval;
    }
    return 0;
}

void freeTree(NODE root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    char postfix[100];
    printf("Enter a postfix expression (use single characters for operands): ");
    scanf("%s", postfix);

    NODE root = buildExpressionTree(postfix);
    printf("Evaluated Result: %d\n", evaluateExpressionTree(root));
    freeTree(root);
    return 0;
}

/*
output:
Enter a postfix expression (use single characters for operands): 23*3/         
Evaluated Result: 2
*/