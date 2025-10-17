# include <stdio.h>
# include <string.h>
# define MAX 16

int n, dist[MAX][MAX];
int min = 16*1000000+1;
int dp[1<<MAX][MAX];
int run(int mask, int x, int start);

int main(void){
    scanf("%d", &n);
    int i, j;
    for (i=0; i<n; i++){
        for (j=0; j<n; j++)
            scanf("%d", &dist[i][j]);
    }
    for (i=0; i<n; i++){
        memset(dp, 0, sizeof(dp));
        int cmp = run(1<<i, i, i);
        if (cmp<min)
            min = cmp;
    }
    printf("%d\n", min);
}

int run(int mask, int x, int start){
    int cost = 16*1000000+1;
    if (dp[mask][x])
        return dp[mask][x];
    if (mask == (1<<n) - 1){
        if (dist[x][start]){
            dp[mask][x] = dist[x][start];
        }
        else {
            dp[mask][x] = cost;
        }
        return dp[mask][x];
    }
    for (int nx=0; nx<n; nx++){
        if (!dist[x][nx])
            continue;
        if (!(mask & (1<<nx))){
            int new_mask = mask | (1<<nx);
            int new_cost = dist[x][nx] + run(new_mask, nx, start);
            if (new_cost < cost)
                cost = new_cost;
        }
    }
    dp[mask][x] = cost;
    return cost;
}