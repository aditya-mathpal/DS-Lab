#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int arr[100], rear;
} ascPQ;

void initpq(ascPQ *apq) {
    apq->rear = -1;
}

void pqinsert(ascPQ *apq, int x) {
    if(apq->rear==99) {
        printf("Queue is full.\n");
        return;
    }
    apq->arr[++apq->rear] = x;
}

int pqmindelete(ascPQ *apq) {
    int min = apq->arr[0], minIndex = 0, i, x;
    if(apq->rear==-1) {
        printf("Queue is empty.\n");
        return -1;
    }
    for(i=1;i<=apq->rear;i++)
        if(min>apq->arr[i]) {
            min = apq->arr[i];
            minIndex = i;
        }
    x = min;
    while(minIndex<=apq->rear) apq->arr[minIndex++] = apq->arr[minIndex+1];
    apq->rear--;
    return x;
}

void displaypq(ascPQ *apq) {
    if(apq->rear==-1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents: ");
    int i=0;
    while(i<=apq->rear) printf("%d\t",apq->arr[i++]);
    printf("\n");
}

int main() {
    ascPQ *apq = (ascPQ*)malloc(sizeof(ascPQ));
    int x;
    initpq(apq);
    printf("Enter 1 to insert, 2 to delete smallest element, 3 to display, 4 to exit:\n");
    do {
        printf("> ");
        scanf("%d",&x);
        switch(x) {
        case 1:
            printf("Enter element to insert: ");
            int num;
            scanf("%d",&num);
            pqinsert(apq,num);
            break;
        case 2:
            printf("%d removed\n",pqmindelete(apq));
            break;
        case 3:
            displaypq(apq);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid input..\n");
        }
    }
    while(x!=4);
    free(apq);
    return 0;
}


/*
output:
Enter 1 to insert, 2 to delete smallest element, 3 to display, 4 to exit:
> 1
Enter element to insert: 7
> 1
Enter element to insert: 8
> 3
Queue contents: 7	8	
> 2
7 removed
> 3
Queue contents: 8	
> 4
Exiting...
*/
