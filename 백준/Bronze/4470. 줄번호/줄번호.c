# include <stdio.h>

int main(void){
    int n, i=1;
    scanf("%d", &n);
    getchar();
    for (; i<=n; i++){
        char x, idx=0;
        char word[55];
        while ((x = getchar()) != '\n')
            word[idx++] = x;
        word[idx] = '\0';
        printf("%d. %s\n", i, word);
    }
}