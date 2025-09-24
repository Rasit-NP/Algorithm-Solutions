# include <stdio.h>

int main(){
    long long r, k, m;
    scanf("%lld %lld %lld", &r, &k, &m);
    int div=m/k;
    while (div>0){
        r = r/2;
        div -= 1;
    }
    printf("%lld\n", r);
    return 0;
}