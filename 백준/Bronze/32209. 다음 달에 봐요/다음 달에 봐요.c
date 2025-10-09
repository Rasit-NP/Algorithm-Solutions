# include <stdio.h>

int main(){
    int q, stack=0;
    scanf("%d", &q);
    int state = 1;
    for (int i=0; i<q; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        if (x==1)
            stack += y;
        else
            stack -= y;
        if (stack < 0)
            state = 0;
    }
    if (state)
        printf("See you next month");
    else
        printf("Adios");
}