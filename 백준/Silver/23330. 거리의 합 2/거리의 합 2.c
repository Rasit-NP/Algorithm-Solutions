# include <stdio.h>
# define MAX 10000001

int cnt[MAX] = {0};
int main(void){
    int n;
    long long ans = 0;
    int count=0;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        cnt[x] += 1;
    }
    for (int i=0; i<MAX; i++){
        ans += (long long) count * i * cnt[i];
        count += cnt[i];
        ans -= (long long) (n-count) * i * cnt[i];
    }
    printf("%lld", ans*2);
}