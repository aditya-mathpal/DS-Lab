#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int info;
    int ex;
    struct node *rlink;
} *NODE;

NODE getHead() {
    NODE head = (NODE)malloc(sizeof(struct node));
    head->rlink = head;
    return head;
}

NODE getNode() {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->rlink = NULL;
    return temp;
}

NODE insertR(NODE head, int n, int e) {
    NODE temp, last;
    temp = (NODE)malloc(sizeof(struct node));
    temp->info = n;
    temp->ex = e;
    last = head;
    while(last->rlink!=head) last = last->rlink;
    last->rlink = temp;
    temp->rlink = head;
    return head;
}

NODE sum(NODE h1, NODE h2, NODE h3) {
    NODE one, two;
    one = h1->rlink;
    two = h2->rlink;
    while (one != h1 && two != h2) {
        if ((one->ex) == (two->ex)) {
            h3 = insertR(h3, ((one->info) + (two->info)), one->ex);
            one = one->rlink;
            two = two->rlink;
        } else if (one->ex > two->ex) {
            h3 = insertR(h3, one->info, one->ex);
            one = one->rlink;
        } else {
            h3 = insertR(h3, two->info, two->ex);
            two = two->rlink;
        }
    }
    while (two != h2) {
        h3 = insertR(h3, two->info, two->ex);
        two = two->rlink;
    }
    while (one != h1) {
        h3 = insertR(h3, one->info, one->ex);
        one = one->rlink;
    }
    return h3;
}

NODE subtract(NODE h1, NODE h2, NODE h3) {
    NODE one, two;
    one = h1->rlink;
    two = h2->rlink;
    while (one != h1 && two != h2) {
        if ((one->ex) == (two->ex)) {
            h3 = insertR(h3, ((one->info) - (two->info)), one->ex);
            one = one->rlink;
            two = two->rlink;
        } else if (one->ex > two->ex) {
            h3 = insertR(h3, one->info, one->ex);
            one = one->rlink;
        } else {
            h3 = insertR(h3, two->info*-1, two->ex);
            two = two->rlink;
        }
    }
    while (two != h2) {
        h3 = insertR(h3, two->info*-1, two->ex);
        two = two->rlink;
    }
    while (one != h1) {
        h3 = insertR(h3, one->info, one->ex);
        one = one->rlink;
    }
    return h3;
}

NODE multiply(NODE h1, NODE h2, NODE h3) {
    NODE one, two;
    one = h1->rlink;
    while (one != h1) {
        two = h2->rlink;
        while (two != h2) {
            int coeff = one->info * two->info;
            int exp = one->ex + two->ex;
            NODE temp = h3->rlink;
            NODE prev = h3;
            int found = 0;
            while (temp != h3) {
                if (temp->ex == exp) {
                    temp->info += coeff;
                    found = 1;
                    break;
                } else if (temp->ex < exp) {
                    break;
                }
                prev = temp;
                temp = temp->rlink;
            }
            if (!found) {
                NODE newTerm = getNode();
                newTerm->info = coeff;
                newTerm->ex = exp;
                newTerm->rlink = temp;
                prev->rlink = newTerm;
            }
            two = two->rlink;
        }
        one = one->rlink;
    }
    return h3;
}

void display(NODE head) {
    NODE temp = head->rlink;
    int first = 1;
    while (temp != head) {
        if(first) {
            printf("%dx^%d", temp->info, temp->ex);
            temp = temp->rlink;
            first = 0;
        }
        else {
            printf(" + %dx^%d", temp->info, temp->ex);
            temp = temp->rlink;
        }
    }
}

void freeLL(NODE head) {
    NODE temp;
    while(head!=NULL) {
        temp = head;
        head = head->rlink;
        free(temp);
    }
}

int main() {
    NODE a = getHead(), b = getHead(), c = getHead();
    printf("Enter 1 to input polynomials, 2 to subtract them, 3 to multiply, 4 to display result, 5 to exit.");
    int choice;
    do {
        printf("\n> ");
        scanf("%d",&choice);
        if(choice==1) {
            printf("Enter number of terms in first polynomial: ");
            int num;
            scanf("%d",&num);
            printf("Enter each term in format <coefficient> <exponent>: ");
            while(num--) {
                int coeff, exp;
                scanf("%d%d",&coeff,&exp);
                a = insertR(a,coeff,exp);
            }
            printf("Enter number of terms in second polynomial: ");
            scanf("%d",&num);
            printf("Enter each term in format <coefficient> <exponent>: ");
            while(num--) {
                int coeff, exp;
                scanf("%d%d",&coeff,&exp);
                b = insertR(b,coeff,exp);
            }
            printf("Entered polynomials are:\n");
            display(a);
            printf("\nand\n");
            display(b);
        }
        else if(choice == 2) {
            c = subtract(a,b,c);
            printf("Subtraction complete.");
        }
        else if(choice == 3) {
            c = multiply(a,b,c);
            printf("Multiplication complete.");
        }
        else if(choice == 4) display(c);
        else if(choice == 5) printf("Exiting");
        else  printf("Enter a valid choice.");
    }
    while(choice!=5);
    return 0;
}

/*
output:
Enter 1 to input polynomials, 2 to subtract them, 3 to multiply, 4 to display result, 5 to exit.
> 1
Enter number of terms in first polynomial: 2
Enter each term in format <coefficient> <exponent>: 2 3 1 2
Enter number of terms in second polynomial: 2
Enter each term in format <coefficient> <exponent>: 2 2 3 1
Entered polynomials are:
2x^3 + 1x^2
and
2x^2 + 3x^1
> 3
Multiplication complete.
> 4
4x^5 + 8x^4 + 3x^3
> 5
Exiting
*/