# include <stdio.h>
# define MAX 1000

int nums[MAX] = {0};

int suffle(int n, int cnt, int idx){
    for (int i=0; i<cnt;){
        idx ++;
        idx = idx==n ? 0 : idx;
        if (!nums[idx])
            i++;
    }
    return idx;
}

int main(void){
    int n, idx = 0;
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        idx = suffle(n, i, idx);
        nums[idx] = i;
        idx = i==n ? 0 : suffle(n, 1, idx);
    }
    for (int i=0; i<n; i++){
        printf("%d ", nums[i]);
    }
}