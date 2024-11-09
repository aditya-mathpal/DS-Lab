#include "queue.h"

int main() {
    queue q;
    int tests,n,k,i;
    scanf("%d",&tests);
    while(tests--) {
        init(&q);
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++) {
            if(i!=k-1) insertq(&q,-1); //anybody other than Vignesh is represented by -1
            else insertq(&q,1); //Vignesh is represented by 1
        }
        while(!isEmpty(&q)) {
            for(i=0;i<2;i++) {
                if(deleteq(&q)==1) {
                    printf("Yes\n");
                    continue;
                }
            }
            if(deleteq(&q)==1) printf("No\n");
        }
    }
}

/*
output:
2 9 6 12 7
No
Yes
*/