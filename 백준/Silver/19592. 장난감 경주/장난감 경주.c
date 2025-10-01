# include <stdio.h>

int main(void){
    int t;
    scanf("%d", &t);
    for (int tc=0; tc<t; tc++){
        int n, x, y;
        int fastest=0;
        int ans, my_v;
        scanf("%d %d %d", &n, &x, &y);
        for (int i=0; i<n-1; i++){
            int v;
            scanf("%d", &v);
            if (v > fastest){
                fastest = v;
            }
        }
        scanf("%d", &my_v);
        if (my_v > fastest){
            ans = 0;
        }
        else if (fastest > x){
            ans = fastest+1;
        }
        else {
            ans = (int) (my_v + x - x * ((double) my_v/fastest)) + 1;
        }

        if (ans > y){
            printf("-1\n");
        }
        else {
            printf("%d\n", ans);
        }
    }
}