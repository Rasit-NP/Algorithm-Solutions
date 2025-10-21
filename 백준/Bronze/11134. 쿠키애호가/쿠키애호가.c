# include <stdio.h>

unsigned int t, n, c;

int main(void){
    scanf("%d", &t);
    for (int i=0; i<t; i++){
        scanf("%d %d", &n, &c);
        int a = n/c, b = n%c;
        if (b)
            printf("%d\n", a+1);
        else
            printf("%d\n", a);
    }
}