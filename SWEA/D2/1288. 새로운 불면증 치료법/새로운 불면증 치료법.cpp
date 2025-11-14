# include <stdio.h>

int main(void){
    int t, tc=1;
    scanf("%d", &t);
    for (;tc<=t; tc++){
        int n, check=0, cnt=0;
        scanf("%d", &n);
        int num = n;
        while (1){
            cnt += 1;
            int x = num;
            while (x>0){
                check = check | (1<<(x%10));
                x /= 10;
            }
            num += n;
            if (check == (1<<10)-1)
                break;
        }
        printf("#%d %lld\n", tc, (long long) cnt*n);
    }
}