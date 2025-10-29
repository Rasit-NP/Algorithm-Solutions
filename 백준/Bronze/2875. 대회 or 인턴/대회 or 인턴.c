# include <stdio.h>

int main(void){
    int n, m, k, cnt=0;
    scanf("%d %d %d", &n, &m, &k);
    while (n+m>=k+3 && n>=2 && m>=1){
        n -= 2;
        m -= 1;
        cnt += 1;
    }
    printf("%d\n", cnt);
}