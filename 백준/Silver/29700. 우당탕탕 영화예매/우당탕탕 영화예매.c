# include <stdio.h>

int main(void){
    int n, m, k, ans=0;
    int i, j;
    scanf("%d %d %d\n", &n, &m, &k);
    for (i=0; i<n; i++){
        int cnt_0 = 0;
        char inputs[5005];
        scanf("%s", inputs);
        for (j=0; j<m; j++){
            char x = inputs[j];
            if (x == '0'){
                cnt_0 += 1;
            }
            else {
                if (cnt_0>=k){
                    ans += cnt_0 - k + 1;
                }
                cnt_0 = 0;
            }
        }
        ans += (cnt_0>=k ? (cnt_0-k+1) : 0);
    }
    printf("%d\n", ans);
}