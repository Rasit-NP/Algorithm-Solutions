# include <stdio.h>
# include <stdlib.h>

int main(void){
    int n, i, cnt=0;
    scanf("%d", &n);
    int* list = malloc(sizeof(int) * n);
    for (i=0; i<n; i++){
        scanf("%d", list+i);
        if (list[i] == i+1){
            cnt += 1;
            list[i] = i == n-1 ? 1 : i+2;
        }
    }
    printf("%d\n", cnt);
    for (i=0; i<n; i++){
        printf("%d ", list[i]);
    }
}