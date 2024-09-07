#include "3_twoStacks.h"

int main() {
    twoStack s;
    init(&s);
    pushToOne(&s,1);
    pushToTwo(&s,2);
    displayOne(&s);
    pushToTwo(&s,3);
    displayTwo(&s);
    printf("%d popped\n",popTwo(&s));
    displayTwo(&s);
    return 0;
}

/*
output:
Stack 1 elements: 1 
Stack 2 elements: 3 2
3 popped
Stack 2 elements: 2
*/