# include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    if (n&1){
        for (int i=0; i<n-1; i += 2){
            printf("1 2 ");
        }
        printf("3 ");
    }
    else {
        for (int i=0; i<n; i += 2){
            printf("1 2 ");
        }
    }
    printf("\n");
}