# include <stdio.h>
# define MAX 100

int n, m, check, cnt=0;
int board[MAX][MAX] = {0};
int visited[MAX][MAX] = {0};

int dfs(int x, int y){
    visited[x][y] = 1;
    for (int nx=x-1; nx<=x+1; nx++){
        for (int ny=y-1; ny<=y+1; ny++){
            if (0<=nx && nx<n && 0<=ny && ny<m){
                if (board[nx][ny] == board[x][y]){
                    if (!visited[nx][ny])
                        dfs(nx, ny);
                }
                else if (board[nx][ny] > board[x][y])
                    check = 0;
            }
        }
    }
}

int main(void){
    int i, j;
    scanf("%d %d", &n, &m);
    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            scanf("%d", &board[i][j]);
        }
    }
    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            if (!visited[i][j]){
                check = 1;
                dfs(i, j);
                cnt += check;
            }
        }
    }
    printf("%d\n", cnt);
}