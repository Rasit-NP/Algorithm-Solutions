# include <stdio.h>
# define max 2500

int main(void){
    int n, m;
    char board[52][52];
    int visited[52][52];
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            visited[i][j] = 0;
        }
    }
    for (int i=0; i<n; i++){
        scanf("%s", board[i]);
    }
    int count = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (visited[i][j]){
                continue;
            }
            int idx = 0, size = 0;
            int queue[max];
            queue[0] = i*m+j;
            visited[i][j] = 1;
            size += 1;
            while (size>0){
                int num = queue[idx];
                int x = num/m, y = num%m;
                idx = (idx+1) % max;
                size -= 1;
                if (board[x][y] == '-'){
                    for (int dy=-1; dy<2; dy=dy+2){
                        int ny = y+dy;
                        if (ny>=0 && ny<m && !(visited[x][ny]) && board[x][ny] == '-'){
                            queue[(idx+size)%max] = x*m+ny;
                            visited[x][ny] = 1;
                            size += 1;
                        }
                    }
                }
                else if (board[x][y] == '|'){
                    for (int dx=-1; dx<2; dx=dx+2){
                        int nx = x+dx;
                        if (nx>=0 && nx<n && !(visited[nx][y]) && board[nx][y] == '|'){
                            queue[(idx+size)%max] = nx*m+y;
                            visited[nx][y] = 1;
                            size += 1;
                        }
                    }
                }
            }
            count += 1;
        }
    }
    printf("%d\n", count);
}