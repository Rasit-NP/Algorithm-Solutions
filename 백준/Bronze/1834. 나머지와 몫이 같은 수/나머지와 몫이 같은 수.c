# include <stdio.h>

int main(){
    int n;
    long long ans = 0;
    scanf("%d", &n);
    for (int i=1; i<n; i++){
        ans += (long long) n*i + i;
    }
    printf("%lld", ans);
}