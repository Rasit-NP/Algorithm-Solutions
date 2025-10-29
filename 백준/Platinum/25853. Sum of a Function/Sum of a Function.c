# include <stdio.h>

char data[1000001] = {0};
int main(void){
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383};
    long long s, e, j;
    int k, i, cnt = 0, ans=0;
    scanf("%lld %lld %d", &s, &e, &k);
    for (i=0; i<76; i++){
        int prime = primes[i];
        for (j=s; j<=e; j++){
            if (data[j-s])
                continue;
            if (j%prime == 0){
                ans += prime;
                cnt += 1;
                data[j-s] = 1;
                if (cnt == k)
                    break;
            }
        }
        if (cnt == k)
            break;
    }
    printf("%d\n", ans);
}