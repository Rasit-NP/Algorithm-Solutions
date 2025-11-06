#include <stdio.h>
#define MAX 1005

int main(void){
    int n, m, i, min = 2000;
    scanf("%d %d", &n, &m);
    for (i=0; i<m; i++){
        int l, r;
        scanf("%d %d", &l, &r);
        min = min > r-l+1 ? r-l+1 : min;
    }
    for (i=0; i<n; i++){
        printf("%d ", (i%min)+1);
    }
}