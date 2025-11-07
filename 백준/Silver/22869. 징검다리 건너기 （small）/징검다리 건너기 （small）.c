# include <stdio.h>
# include <stdlib.h>
# define MAXQ 5080

int values[MAXQ] = {0};
int queue[MAXQ] = {0};
int visited[MAXQ] = {0};

int main(void){
    int n, k, i, ans = 0;
    int head = 0, size = 0;
    scanf("%d %d", &n, &k);
    for (i=0; i<n; i++)
        scanf("%d", &values[i]);
    visited[0] = 1;
    queue[head+(size++)] = 0;
    while (size){
        int nx, x = queue[head++];
        head %= MAXQ;
        size -= 1;
        if (x==n-1){
            ans = 1;
            break;
        }
        for (nx=x+1; nx<n; nx++){
            if (!visited[nx] && (nx-x)*(1+abs(values[x]-values[nx]))<=k){
                visited[nx] = 1;
                queue[(head+size++)%MAXQ] = nx;
            }
        }
    }
    if (ans)
        printf("YES");
    else
        printf("NO");
}