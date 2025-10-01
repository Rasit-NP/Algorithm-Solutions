# include <stdio.h>

int main(void){
    int n, m;
    long long ans=0;
    scanf("%d %d", &n, &m);
    for (int i=0; i<n+m; i++){
        long long value;
        scanf("%lld", &value);
        ans += value;
    }
    printf("%lld\n", ans);
}