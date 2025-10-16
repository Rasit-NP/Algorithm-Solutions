# include <stdio.h>

double comb(int N, int K){
    if (K>N){
        return 0;
    }
    if (K>N-K)
        K = N-K;
    double ans = 1;
    for (int i=1; i<=K; i++){
        ans *= (double)(N-i+1);
        ans /= (double)(K-i+1);
    }
    return ans;
}

int main(void){
    int m, k, total=0, n[50]={0};
    double ans=0;
    scanf("%d", &m);
    for (int i=0; i<m; i++){
        scanf("%d", n+i);
        total += n[i];
    }
    scanf("%d", &k);
    for (int i=0; i<m; i++){
        ans += comb(n[i], k);
    }
    ans /= comb(total, k);
    printf("%.12lf", ans);
}