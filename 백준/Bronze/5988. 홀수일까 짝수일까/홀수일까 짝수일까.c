# include <stdio.h>
# include <string.h>

int main(void){
    int n, i;
    scanf("%d", &n);
    for (i=0; i<n; i++){
        char k[65];
        scanf("%s", k);
        int len = strlen(k);
        int x = (int) k[len-1] - 48;
        if (x&1)
            printf("odd\n");
        else
            printf("even\n");
    }
}