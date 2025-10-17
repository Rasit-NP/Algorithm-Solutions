# include <stdio.h>
# include <string.h>
# define MAX 1<<16

int init(int);
int dfs(int, int);
int n, dp[MAX][16];
typedef struct{
    int len;
    char start, end;
} Word;
Word words[MAX];

int main(void){
    scanf("%d", &n);
    init(n);
    int i, ans = 0;
    for (i=0; i<n; i++){
        int cmp = dfs(1<<i, i);
        if (cmp > ans)
            ans = cmp;
    }
    printf("%d\n", ans);
}

int init(int n){
    for (int i=0; i<n; i++){
        char word[105];
        scanf("%s", word);
        words[i].len = strlen(word);
        words[i].start = word[0];
        words[i].end = word[words[i].len-1];
    }
    for (int i=0; i<1<<n; i++){
        for (int j=0; j<n; j++)
            dp[i][j] = 0;
    }
    return 0;
}

int dfs(int mask, int x){
    if (dp[mask][x])
        return dp[mask][x];
    int total = words[x].len;
    for (int nx=0; nx<n; nx++){
        if (nx==n)
            continue;
        if (!(mask&(1<<nx)) && words[x].end == words[nx].start){
            int new_mask = mask | (1<<nx);
            int cmp = words[x].len + dfs(new_mask, nx);
            if (cmp>total)
                total = cmp;
        }
    }
    dp[mask][x] = total;
    return total;
}