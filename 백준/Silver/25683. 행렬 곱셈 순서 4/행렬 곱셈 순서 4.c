# include <stdio.h>

int main(void){
    int n, i;
    long long sum=0;
    scanf("%d", &n);
    for (i=0; i<n; i++){
        int r, c;
        scanf("%d %d", &r, &c);
        if (i==n-1){
            sum *= c;
        }
        else {
            sum += r*c;
        }
    }
    printf("%lld", sum);
}