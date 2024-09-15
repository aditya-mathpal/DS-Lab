#include "circular_queue.h"

int main() {
    cQueue q;
    initcq(&q);
    insertcq(&q,"hello this is a");
    insertcq(&q,"test");
    displaycq(q);
    deletecq(&q);
    insertcq(&q,"complete");
    displaycq(q);
}

/*
output:

Queue is:
hello this is a
test

Queue is:
test
complete
*/