# include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc<=t; tc++){
        int n;
        scanf("%d", &n);
        printf("Pairs for %d: ", n);
        for (int i=1; i<=n/2; i++){
            int a=i, b=n-i;
            if (a<b){
                printf("%d %d", a, b);
            }
            if (b-a > 2){
                printf(", ");
            }
        }
        printf("\n");
    }
    return 0;
}