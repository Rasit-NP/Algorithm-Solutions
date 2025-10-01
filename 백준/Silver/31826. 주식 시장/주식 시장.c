# include <stdio.h>
# define min 7000
# define max 13000

int main(void){
    int orders[max-min+1] = {0};
    int n, now_value=10000;
    scanf("%d", &n);
    for (int trade=0; trade<n; trade++){
        int p, x, f;
        scanf("%d %d %d", &p, &x, &f);
        int idx=p-min;
        if (f*orders[idx] < 0){
            orders[idx] += f*x;
            now_value = p;
        }
        else {
            orders[idx] += f*x;
        }
    }
    printf("%d", now_value);
}