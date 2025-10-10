# include <stdio.h>
# define MAX 10005

int tails[MAX]={0};

int main(){
    int t;
    scanf("%d", &t);
    for (int tc=1; tc<=t; tc++){
        int n, k, tails_max=0;
        scanf("%d %d", &n, &k);
        for (int i=0; i<n; i++){
            int x;
            scanf("%d", &x);
            if (!(tails_max) || x > tails[tails_max-1]){
                tails[tails_max] = x;
                tails_max += 1;
                continue;
            }
            else {
                int l=-1, r = tails_max;
                while (r-l > 1){
                    int mid = (l+r)/2;
                    if (x > tails[mid]){
                        l = mid;
                    }
                    else {
                        r = mid;
                    }
                }
                tails[r] = x;
            }
        }
        printf("Case #%d\n", tc);
        if (tails_max >= k)
            printf("1\n");
        else
            printf("0\n");
    }
}