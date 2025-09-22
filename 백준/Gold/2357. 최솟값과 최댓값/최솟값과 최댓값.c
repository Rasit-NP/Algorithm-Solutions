#include <stdio.h>

int main(){
    
    int n;
    int m, num;
    int size = 1;
    scanf("%ld %d", &n, &m);
    while (size<=n){
        size *= 2;
    }

    int tree[size*2][2];
    for (int i=0; i<size*2; i++){
        tree[i][0] = 1000000001;
        tree[i][1] = 0;
    }
    for (int i=size; i<size+n; i++){
        scanf("%d", &num);
        tree[i][0] = num;
        tree[i][1] = num;
    }

    for (int i = size-1; i>0; i--){
        if (tree[2*i][0] <= tree[2*i+1][0]){
            tree[i][0] = tree[2*i][0];
        }
        else {
            tree[i][0] = tree[2*i+1][0];
        }
        if (tree[2*i][1] >= tree[2*i+1][1]){
            tree[i][1] = tree[2*i][1];
        }
        else {
            tree[i][1] = tree[2*i+1][1];
        }
    }

    for (int i=0; i<m; i++){
        int a, b, l, r;
        int min=1000000001, max=0;
        scanf("%d %d", &a, &b);
        l = size + a - 1;
        r = size + b - 1;
        while (l<=r){
            if (tree[l][0] < min){
                min = tree[l][0];
            }
            if (tree[l][1] > max){
                max = tree[l][1];
            }
            if (tree[r][0] < min){
                min = tree[r][0];
            }
            if (tree[r][1] > max){
                max = tree[r][1];
            }
            if (l&1){
                l++;
            }
            if (!(r&1)){
                r--;
            }
            l /= 2;
            r /= 2;
        }
        printf("%d %d\n", min, max);
    }

    return 0;
}