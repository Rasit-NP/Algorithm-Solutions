# include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    int gap = (n+6) % 10;
    char ja = (n+8) % 12 + 'A';
    printf("%c%d\n", ja, gap);
}