# include <stdio.h>
# define mod 1000000007

int size=1;
long long tree[2097152];

int init(int n){
    while (size <= n){
        size <<= 1;
    }
    for (int i=0; i<2*size; i++){
        tree[i] = 1;
    }
    for (int i=0; i<n; i++){
        scanf("%lld", &tree[size+i]);
    }
    for (int i = size-1; i>0; i--){
        tree[i] = (tree[i*2]*tree[i*2+1]) % mod;
    }
    return 0;
}

int update(int i, long long v){
    int idx = size+i-1;
    tree[idx] = v;
    idx /= 2;
    while (idx > 0){
        tree[idx] = (tree[idx*2]*tree[idx*2+1]) % mod;
        idx /= 2;
    }
    return 0;
}

int calculate(int i, long long j){
    int l = size+i-1;
    int r = size+j-1;
    long long ans=1;
    while (l<=r){
        if (l&1){
            ans = (ans * tree[l]) % mod;
            l++;
        }
        if (!(r&1)){
            ans = (ans * tree[r]) % mod;
            r--;
        }
        l /= 2;
        r /= 2;
    }
    printf("%lld\n", ans);
    return 0;
}

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    init(n);
    for (int i=0; i<m+k; i++){
        int q, a;
        long long b;
        scanf("%d %d %lld", &q, &a, &b);
        if (q==1){
            update(a, b);
        }
        else {
            calculate(a, b);
        }
    }
}