/*
write a program to manage an emergency room capable of occupying 50 patients, using a priority 
queue to manage incoming patients. Patients with more severe levels (e.g., critical=4, serious=3, 
moderate=2, mild =1) conditions have higher priority and should be seen before others, even if they 
arrive later. Write a function that adds patients to the queue ( with patient name and sever level of a 
patient ) to a priority queue based on their severity when they arrive and retrieves them in the correct 
order for treatment.
*/

#include<stdio.h>
#include<string.h>

typedef enum {
    mild = 1,
    moderate = 2,
    serious = 3,
    critical = 4
} severity;

typedef struct {
    char name[100];
    severity s;
} patient;

typedef struct {
    patient p[50];
    int front, rear;
} pQueue;

void init(pQueue* pq) {
    pq->front = pq->rear = -1;
}

void enqueue(pQueue* pq, patient p) {
    if(pq->rear==49) {
        printf("Waiting room is full\n");
        return;
    }
    if(pq->front==-1) pq->front++;
    pq->p[++pq->rear] = p;
}

patient dequeue(pQueue* pq) {
    if(pq->front==-1) {
        printf("Waiting room is empty\n");
        patient p = {"",0};
        return p;
    }
    for(int s = 4;s>=1;s--) {
        for(int i=pq->front;i<=pq->rear;i++) {
            if(pq->p[i].s == s) {
                patient temp = pq->p[i];
                for(int j=i;j<pq->rear;j++) {
                    pq->p[j] = pq->p[j+1];
                }
                pq->rear--;
                if(pq->rear<pq->front) pq->rear = pq->front = -1;
                return temp;
            }
        }
    }
}

void display(pQueue pq) {
    if(pq.front==-1) {
        printf("Waiting room is empty\n");
        return;
    }
    printf("Patient list:\n");
    for(int i = pq.front; i<=pq.rear; i++) {
        printf("Name: %s, severity: %d\n",pq.p[i].name,pq.p[i].s);
    }
}

int main() {
    pQueue pq;
    init(&pq);
    int x;
    printf("Enter 1 to register patient, 2 to treat patient with highest priority, 3 to display patient list, Ctrl-C to exit\n");
    while(1) {
        printf("> ");
        scanf("%d",&x);
        getchar(); //consume newline
        if(x == 1) {
            patient p;
            printf("Enter name: ");
            fgets(p.name,100,stdin);
            p.name[strlen(p.name)-1] = 0; //removing newline
            printf("Enter severity\nmild = 1, moderate = 2, serious = 3, critical = 4\n> ");
            int temp;
            scanf("%d",&temp);
            getchar();
            p.s = temp;
            enqueue(&pq,p);
        }
        else if(x == 2) {
            patient p = dequeue(&pq);
            if(strlen(p.name)>0) printf("Send in %s, severity %d\n",p.name,p.s);
        }
        else if(x == 3) display(pq);
        else printf("Try again\n");
    }
    return 0;
}

/*
sample output:
Enter 1 to register patient, 2 to treat patient with highest priority, 3 to display patient list, Ctrl-C to exit
> 1
Enter name: Aditya Mathpal
Enter severity
mild = 1, moderate = 2, serious = 3, critical = 4
> 1
> 1
Enter name: Aryan Kudva
Enter severity
mild = 1, moderate = 2, serious = 3, critical = 4
> 4
> 3
Patient list:
Name: Aditya Mathpal, severity: 1
Name: Aryan Kudva, severity: 4
> 2
Send in Aryan Kudva, severity 4
> 3
Patient list:
Name: Aditya Mathpal, severity: 1
> 2
Send in Aditya Mathpal, severity 1
> 3
Waiting room is empty
> 2
Waiting room is empty
>
*/