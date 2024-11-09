#include "two_circular_queues.h"

int main() {
    dcQueue q;
    initcq(&q);
    insertcqOne(&q,1);
    insertcqOne(&q,3);
    insertcqTwo(&q,2);
    insertcqTwo(&q,4);
    displaycq1(q);
    displaycq2(q);
    deletecqTwo(&q);
    displaycq2(q);
}

/*
output:

Queue 1 is:
1
3

Queue 2 is:
2
4

Queue 2 is:
4
*/