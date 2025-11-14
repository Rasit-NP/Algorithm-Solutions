# include <stdio.h>

int main(void){
    int t, tc=1;
    scanf("%d", &t);
    for (;tc<=t; tc++){
        int n, m, i=0;
        scanf("%d %d", &n, &m);
        int check = (m & ((1<<n)-1)) + 1;
        if (check>>n)
            printf("#%d ON\n", tc);
        else
            printf("#%d OFF\n", tc);
    }
}