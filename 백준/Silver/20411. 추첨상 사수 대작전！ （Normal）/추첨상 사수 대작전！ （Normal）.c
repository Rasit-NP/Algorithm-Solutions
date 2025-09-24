# include <stdio.h>

int main(){
    long long m, seed, x1, x2;
    scanf("%lld %lld %lld %lld", &m, &seed, &x1, &x2);
    long long d0 = seed-x1;
    long long d1 = x1-x2;
    long long a = 0;
    long long c = -1;
    while ((a*d0-d1)%m){
        a += 1;
    }
    long long dk = (a*d0-d1)/m;
    long long k1, k2;
    if (dk>0){
        k2 = 0;
        k1 = k2 + dk;
    }
    else if (dk == 0){
        k1 = 0;
        k2 = 0;
    }
    else {
        k1 = 0;
        k2 = k1 - dk;
    }
    c = k1*m + x1 - a*seed;
    while (c < 0){
        k1++;
        k2++;
        c = k1*m + x1 - a*seed;
    }
    printf("%lld %lld\n", a, c);

    return 0;
}