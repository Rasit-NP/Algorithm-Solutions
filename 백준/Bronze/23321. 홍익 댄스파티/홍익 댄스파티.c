# include <stdio.h>
# include <string.h>

char change(int row, int state){
    char board[5][3] = {{'.', 'o', '.'}, {'o', 'w', '.'}, {'m', 'l', 'o'}, {'l', 'n', 'L'}, {'n', '.', 'n'}};
    if (state == 2){
        return board[row][2];
    }
    else{
        return board[row][!state];
    }
}

int main(){
    char now_dance[5][10005];
    int state[10005];           // (0, 1, 2): (도약 준비, 도약 중, 착석)
    for (int i=0; i<5; i++){
        scanf("%s", now_dance[i]);
    }
    int len = strlen(now_dance[0]);
    for (int i=0; i<len; i++){
        if (now_dance[1][i] == 'o'){
            state[i] = 0;
        }
        else if (now_dance[1][i] == 'w'){
            state[i] = 1;
        }
        else {
            state[i] = 2;
        }
    }

    for (int i=0; i<5; i++){
        for (int j=0; j<len; j++){
            printf("%c", change(i, state[j]));
        }
        printf("\n");
    }

    return 0;
}