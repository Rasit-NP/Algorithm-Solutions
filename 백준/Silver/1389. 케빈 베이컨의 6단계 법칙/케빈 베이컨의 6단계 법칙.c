# include <stdio.h>
# define MAX 10000

int main(void){
    int n, m;
    int visited[101][101];
    int edges[101][101];
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            visited[i][j] = 101;
            edges[i][j] = 0;
        }
        visited[i][i] = 0;
    }
    for (int i=0; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        edges[a][b] = 1;
        edges[b][a] = 1;
    }
    int ans=-1;
    int maximum = 5051;
    for (int start=1; start<=n; start++){
        int queue[MAX] = {0};
        int idx=0, size=0;
        int total=0;
        queue[idx] = start;
        size += 1;
        while (size){
            int x = queue[idx];
            size -= 1, idx = (idx + 1) % MAX;
            for (int nx=1; nx<=n; nx++){
                if (edges[x][nx] && (visited[start][x]+1 < visited[start][nx])){
                    queue[(idx+size)%MAX] = nx;
                    visited[start][nx] = visited[start][x] + 1;
                    size += 1;
                }
            }
        }
        for (int i=1; i<=n; i++){
            total += visited[start][i];
        }
        if (maximum>total){
            maximum = total;
            ans = start;
        }
    }
    printf("%d\n", ans);
}