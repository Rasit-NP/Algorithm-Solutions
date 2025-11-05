# include <stdio.h>
# include <string.h>
# define MAX 100000

int height[MAX];
int n, m;

int base(int m, char board[][m], int x){
    int i, j;
    for (i=0; i<n-x; i++){
        for (j=0; j<m; j++)
            board[i][j] = 46;
    }
    for (i=n-x; i<n; i++){
        for (j=0; j<m; j++){
            if (i==n-x)
                board[i][j] = 45;
            else{
                if (j%3==2)
                    board[i][j] = 124;
            }
        }
    }
}

int mountain(int m, char board[][m]){
    int i, j;
    for (j=0; j<m; j++){
        for (i=n-height[j]; i<n; i++){
            if (board[i][j]==45)
                board[i][j] = 42;
            else
                board[i][j] = 35;
        }
    }
}

int result(int m, char board[][m]){
    int i, j;
    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

int main(void){
    int x, i;
    scanf("%d %d %d", &n, &m, &x);
    char board[n][m];
    memset(board, 46, sizeof(board));
    base(m, board, x);
    for (i=0; i<m; i++)
        scanf("%d", &height[i]);
    mountain(m, board);
    result(m, board);
}