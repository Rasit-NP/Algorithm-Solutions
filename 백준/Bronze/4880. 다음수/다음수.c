# include <stdio.h>

int main(){
    while (1){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a==0 && b==0 && c==0){
            break;
        }
        int d1=b-a, d2=c-b;
        if (d1==d2){
            printf("AP %d\n", c+d1);
        }
        else {
            d1 = b/a;
            printf("GP %d\n", c*d1);
        }
    }
    return 0;
}