# include <stdio.h>
# define N 3
# define MAX_Q 20

int main(void){
    int i, j, k, n, ans=0;
    int qx[MAX_Q], qy[MAX_Q];
    int board[N][N], visited[N][N];
    int head = 0, size = 0;
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    scanf("%d", &n);
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            scanf("%d", &board[i][j]);
            visited[i][j] = 0;
        }
    }
    visited[0][0] = 1;
    qx[head+size] = 0, qy[head+size] = 0;
    size++;
    while (size){
        int x = qx[head], y = qy[head];
        if (x==n-1 && y==n-1){
            ans = 1;
            break;
        }
        head++;
        head = (head == MAX_Q) ? 0 : head;
        size--;
        if (!board[x][y])
            continue;
        for (int k=0; k<4; k++){
            int jump = board[x][y];
            int nx = x+jump*dx[k], ny = y+jump*dy[k];
            if (nx<0 | nx>=n | ny<0 | ny>=n | visited[nx][ny])
                continue;
            visited[nx][ny] = 1;
            int idx = (head+size >= MAX_Q) ? head+size-n : head+size;
            qx[idx] = nx, qy[idx] = ny;
            size++;
        }
    }
    if (ans)
        printf("HaruHaru");
    else
        printf("Hing");
}