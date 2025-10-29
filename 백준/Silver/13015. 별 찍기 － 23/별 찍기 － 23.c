# include <stdio.h>

int head_tail(int n){
    int i;
    for (i=0; i<n; i++){
        printf("*");
    }
    for (i=0; i<2*n-3; i++){
        printf(" ");
    }
    for (i=0; i<n; i++){
        printf("*");
    }
    printf("\n");
}

int middle(int n){
    int i, j;
    for (i=1; i<n-1; i++){
        for (j=0; j<i; j++)
            printf(" ");
        printf("*");
        for (j=0; j<n-2; j++)
            printf(" ");
        printf("*");
        for (j=0; j<2*n-3-2*i; j++)
            printf(" ");
        printf("*");
        for (j=0; j<n-2; j++)
            printf(" ");
        printf("*");
        printf("\n");
    }
    for (i=0; i<n-1; i++)
        printf(" ");
    printf("*");
    for (i=0; i<n-2; i++)
        printf(" ");
    printf("*");
    for (i=0; i<n-2; i++)
        printf(" ");
    printf("*\n");
    for (i=n-2; i>0; i--){
        for (j=0; j<i; j++)
            printf(" ");
        printf("*");
        for (j=0; j<n-2; j++)
            printf(" ");
        printf("*");
        for (j=0; j<2*n-3-2*i; j++)
            printf(" ");
        printf("*");
        for (j=0; j<n-2; j++)
            printf(" ");
        printf("*");
        printf("\n");
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    head_tail(n);
    middle(n);
    head_tail(n);
}