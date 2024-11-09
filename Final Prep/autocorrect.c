/*
Write a C program to implement a simple spell check suggestion system using a binary tree, 
where  each  node  contains  a  common  word.  Use  Inorder  traversal  to  suggest  words  in 
alphabetical order when given a prefix.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    char word[100];
    struct node *left, *right;
} Node;

Node* getNode(char* s) {
    Node* temp = (Node*)malloc(sizeof(Node));
    strcpy(temp->word,s);
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* root, char* s) {
    if(root==NULL) return getNode(s);
    if(strcmp(root->word,s)>0) root->left = insert(root->left,s);
    if(strcmp(root->word,s)<0) root->right = insert(root->right,s);
    return root;
}

void suggest(Node* root, char* s) {
    if(root==NULL) return;
    suggest(root->left,s);
    if(strncmp(root->word,s,strlen(s))==0) printf("%s\n",root->word);
    suggest(root->right,s);
}

void freeTree(Node* root) {
    if(root==NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node* root = NULL;
    char wordList[][100] = {"the", "be", "to", "of", "and", "a", "in", "that", "have", "I"};
    int len = sizeof(wordList)/sizeof(wordList[0]);
    for(int i = 0;i<len;i++) root = insert(root,wordList[i]);
    printf("Enter the beginning of your word: ");
    char str[100];
    fgets(str,100,stdin);
    str[strlen(str)-1] = 0;
    suggest(root,str);
    return 0;
}

/*
sample output:
Enter the beginning of your word: t
that
the
to
*/