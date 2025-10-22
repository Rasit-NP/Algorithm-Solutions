# include <stdio.h>

int main(void){
    int n, m, a;
    scanf("%d %d %d", &n, &m, &a);
    int me = (m+1)/2;
    while (1){
        int x;
        scanf("%d", &x);
        if (x == me){
            printf("0\n");
            break;
        }
        a += x-me;
        if (a>n)
            a -= n;
        else if (a<=0)
            a += n;
        printf("%d\n", a);
    }
}