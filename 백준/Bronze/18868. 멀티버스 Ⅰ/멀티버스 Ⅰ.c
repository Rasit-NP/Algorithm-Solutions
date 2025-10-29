# include <stdio.h>
# include <string.h>
# define MAX 10000
# define MAX2 100

int size[MAX+1];

int main(void){
    int m, n, i, j;
    scanf("%d %d", &m, &n);
    int planets[10][MAX2] = {0};
    for (i=0; i<m; i++){
        int cnt = 0;
        memset(size, 0, sizeof(size));
        for (j=0; j<n; j++){
            scanf("%d", &planets[i][j]);
            size[planets[i][j]] = 1;
        }
        for (j=0; j<=MAX; j++){
            if (size[j]){
                cnt += 1;
                size[j] = cnt;
            }
        }
        for (j=0; j<n; j++){
            planets[i][j] = size[planets[i][j]];
        }
    }
    int cnt = 0;
    for (i=0; i<m-1; i++){
        for (j=i+1; j<m; j++){
            int check = 1;
            for (int k=0; k<n; k++){
                if (planets[i][k] != planets[j][k]){
                    check = 0;
                    break;
                }
            }
            if (check)
                cnt += 1;
        }
    }
    printf("%d\n", cnt);
}