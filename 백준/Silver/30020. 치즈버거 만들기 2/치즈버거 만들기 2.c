# include <stdio.h>

int main(void){
    int a, b;
    scanf("%d %d", &a, &b);
    int num = a - b;
    if (num <= 0 || num > b){
        printf("NO");
        return 0;
    }
    printf("YES\n%d\n", num);
    for (int i=0; i<num; i++){
        if (i == num-1){
            for (int j=0; j<b-num+1; j++)
                printf("ab");
            printf("a\n");
        }
        else
            printf("aba\n");
    }
}