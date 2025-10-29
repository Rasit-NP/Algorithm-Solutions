# include <stdio.h>

int a(int* n, int* m){
    int x = *n, y = *m;
    *n = (x+2)%4;
}

int b(int* n, int* m){
    int x = *n, y = *m;
    if (*n > 1)
        x -= 2;
    x = !x;
    y = !y;
    if (*n > 1)
        x += 2;
    *n = x;
    *m = y;
}

int c(int* n, int* m){
    int x = *n, y = *m;
    *n = 3-x;
    *m = 1-y;
}

int d(int* n, int* m){
    int x = *n, y = *m;
    if (x==0 && y==0){
        *m = 1;
    }
    else if (x==3 && y==1){
        *m = 0;
    }
    else if (y==0){
        *n -= 1;
    }
    else if (y==1){
        *n += 1;
    }
}
char orders[3005];
int main(void){
    int n, m, k;
    scanf("%d %d", &n, &m);
    scanf("%d", &k);
    n -= 1;
    m -= 1;
    scanf("%s", orders);
    for (int i=0; i<k; i++){
        char order = orders[i];
        if (order == 'A')
            a(&n, &m);
        else if (order == 'B')
            b(&n, &m);
        else if (order == 'C')
            c(&n, &m);
        else if (order == 'D')
            d(&n, &m);
    }
    n += 1;
    m += 1;
    printf("%d %d\n", n, m);
}