# include <stdio.h>
int main(void){
    int x, n, sum=0;
    scanf("%d\n%d", &x, &n);
    for (int i=0; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        sum += a*b;
    }
    if (sum == x)
        printf("Yes");
    else
        printf("No");
}