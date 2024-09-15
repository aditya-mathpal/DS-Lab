#include "StackStackButQueue.h"

int main() {
    staqueue sq;
    initQ(&sq);
    insertQ(&sq,5);
    insertQ(&sq,6);
    displayQ(&sq);
    deleteQ(&sq);
    displayQ(&sq);
    return 0;
}

/*
output:

The queue is:
5
6

The queue is:
6
*/