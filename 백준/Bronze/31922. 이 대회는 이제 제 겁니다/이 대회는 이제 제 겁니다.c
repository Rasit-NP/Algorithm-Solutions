# include <stdio.h>

int main(void){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int ans = (a+c) >= b ? a+c : b;
    printf("%d", ans);
}