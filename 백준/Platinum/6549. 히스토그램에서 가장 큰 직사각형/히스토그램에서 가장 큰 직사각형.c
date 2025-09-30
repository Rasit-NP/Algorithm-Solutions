# include <stdio.h>

int n;
int size;
int tree[400000];
int tree_idx[400000];
long long maximum;

void init(int n){
    while (size<n){
        size *= 2;
    }
    for (int i=0; i<n; i++){
        scanf("%d", &tree[size+i]);
        tree_idx[size+i] = i+1;
    }
    for (int i = size+n; i<2*size; i++){
        tree[i] = 1000000001;
    }
    for (int i=size-1; i>0; i--){
        if (tree[2*i] <= tree[2*i+1]){
            tree[i] = tree[2*i];
            tree_idx[i] = tree_idx[2*i];
        }
        else {
            tree[i] = tree[2*i+1];
            tree_idx[i] = tree_idx[2*i+1];
        }
    }
}

int sep(int i, int j){
    int l = size+i-1, r = size+j-1;
    int min_local = 1000000001, min_idx=-1;
    while (l<=r){
        if (l&1){
            if (tree[l] < min_local){
                min_local = tree[l];
                min_idx = tree_idx[l];
            }
            l++;
        }
        if (!(r&1)){
            if (tree[r] < min_local){
                min_local = tree[r];
                min_idx = tree_idx[r];
            }
            r--;
        }
        l /= 2;
        r /= 2;
    }
    return min_idx;
}

int cal(int i, int j){
    int min_idx = sep(i, j);
    int min_local = tree[size+min_idx-1];
    if ((long long)min_local*(j-i+1) > maximum){
        maximum = (long long)min_local*(j-i+1);
    }
    if (i<min_idx && min_idx<j){
        cal(i, min_idx-1);
        cal(min_idx+1, j);
    }
    else if (i==j){
        return 0;
    }
    else if (i == min_idx){
        cal(min_idx+1, j);
    }
    else if (j == min_idx){
        cal(i, min_idx-1);
    }
    return 0;
}

int main(){
    while (1){
        scanf("%d", &n);
        if (n==0) break;
        size = 1;
        maximum = 0;
        init(n);
        cal(1, n);
        printf("%lld\n", maximum);
    }
    return 0;
}