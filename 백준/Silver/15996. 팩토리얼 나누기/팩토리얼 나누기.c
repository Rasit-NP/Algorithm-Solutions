# include <stdio.h>

int main(void){
    int n, a;
    scanf("%d %d", &n, &a);
    int ans=0;
    while (n>1){
        ans += n/a;
        n /= a;
    }
    printf("%d\n", ans);
}