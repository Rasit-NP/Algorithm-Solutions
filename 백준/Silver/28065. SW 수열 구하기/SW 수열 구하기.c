# include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    int cmp = n/2;
    for (int i=n-1; i>=0; i--){
        static int x = 1;
        printf("%d ", x);
        if (x>cmp)
            x -= i;
        else if (x<=cmp)
            x += i;
    }
}