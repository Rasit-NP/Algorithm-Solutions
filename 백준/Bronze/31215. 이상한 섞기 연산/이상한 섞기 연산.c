# include <stdio.h>

int main(void){
    int t, tc=1;
    scanf("%d", &t);
    for (;tc<=t;tc++){
        int n;
        scanf("%d", &n);
        if (n<3)
            printf("1\n");
        else
            printf("3\n");
    }
}