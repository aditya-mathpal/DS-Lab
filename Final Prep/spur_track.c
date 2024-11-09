/*
Given a left, right, and a spur track as shown in the below figure. There are N trucks numbered 
1, 2, ..., N are on the line arranged in the left track and it is desired to rearrange(permute) the 
trucks as they leave on the right-hand track. We can move directly N trucks to the right track 
but there can be more possibilities of moving the trucks to the right track using the spur track. 
We can move any truck to spur track and then move it to the right track. The task is to print all 
the possible permutation orders in which all the N trucks can be moved from left track to right 
track. Once a truck is moved from left track to right/spur track then it can’t be moved to left 
track again. For example, if N = 3, and we have the trucks numbered 1,2,3 on the left track, 
then 3 first goes to the spur track. We could then send 2 to the spur, then on the way to its 
right,  then  send  3  on  the  way,  then  1,  obtaining  the  new  order  1,3,2.  Using  suitable  data 
structure write a ‘C’ program to print all possible permutation moves for a given N of trucks.
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct stack {
    int top, truck[MAX];
} STACK;

void init(STACK* s) {
    s->top = -1;
}

int isEmpty(STACK *s) {
    return s->top==-1;
}

int isFull(STACK *s) {
    return s->top==MAX-1;
}

void push(STACK* s, int x) {
    if(isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->truck[++s->top] = x;
}

int pop(STACK* s) {
    if(isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->truck[s->top--];
}

void perm(int* left, int lIndex, int len, STACK* spur, int* right, int rIndex) {
    if(isEmpty(spur) && lIndex == len) {
        for(int i=0;i<len;i++) printf("%5d",right[i]);
        printf("\n");
        return;
    }
    if(!isEmpty(spur)) {
        int temp = pop(spur);
        right[rIndex] = temp;
        perm(left, lIndex, len, spur, right, rIndex+1);
        push(spur,temp);
    }
    if(lIndex < len) {
        right[rIndex] = left[lIndex];
        perm(left, lIndex+1, len, spur, right, rIndex+1);
        push(spur,left[lIndex]);
        perm(left, lIndex+1, len, spur, right, rIndex);
        pop(spur);
    }
}

int main() {
    int left[3] = {1, 2, 3};
    int right[3] = {0};
    STACK spur;
    init(&spur);
    perm(left, 0, 3, &spur, right, 0);
    return 0;
}

/*
output for 3 trucks:
    1    2    3
    1    2    3
    1    2    3
    1    2    3
    1    3    2
    1    3    2
    1    2    3
    1    2    3
    1    2    3
    1    2    3
    1    3    2
    1    3    2
    2    1    3
    2    1    3
    2    3    1
    2    3    1
    2    1    3
    2    1    3
    2    3    1
    2    3    1
    3    2    1
    3    2    1
*/