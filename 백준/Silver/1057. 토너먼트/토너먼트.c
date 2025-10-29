# include <stdio.h>

int main(void){
    int n, a, b, size=1, round = 0;
    scanf("%d %d %d", &n, &a, &b);
    while (size < n)
        size *= 2;
    a += size - 1;
    b += size - 1;
    while (a != b){
        a /= 2;
        b /= 2;
        round += 1;
    }
    printf("%d\n", round);
}