# include <stdio.h>

int r, c, k, sr, sc;
int board[1000][1000]={0};
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

int main(void){
    scanf("%d %d", &r, &c);
    scanf("%d", &k);
    for (int i=0; i<k; i++){
        int br, bc;
        scanf("%d %d", &br, &bc);
        board[br][bc] = 1;
    }
    scanf("%d %d", &sr, &sc);
    int x=sr, y=sc;
    int orders[4];
    scanf("%d %d %d %d", &orders[0], &orders[1], &orders[2], &orders[3]);
    int idx = 0;
    int update = 0;
    board[x][y] = 1;
    while (update<=4){
        int order = orders[idx++];
        idx %= 4;
        int nx = x+dx[order], ny = y+dy[order];
        while (nx>=0 && nx<r && ny>=0 && ny<c && !board[nx][ny]){
            board[x][y] = 1;
            x = nx, y = ny;
            nx = x+dx[order], ny = y+dy[order];
            update=0;
        }
        update++;
    }
    printf("%d %d\n", x, y);
}