# include <stdio.h>

int main(void){
    long long a, b, ans;
    scanf("%lld %lld", &a, &b);
    ans = ((b+a)*((a<b?b-a:a-b)+1))/2;
    printf("%lld\n", ans);
}