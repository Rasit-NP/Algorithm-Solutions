# include <stdio.h>

char input[1000005];
int scores[1000005];
int main(void){
    int board[26] = {3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1};
    int len;
    scanf("%s", input);
    len = strlen(input);
    for (int i=0; i<len; i++){
        scores[i] = board[(int)input[i] - 65];
    }
    while (len>1){
        int times = len/2;
        for (int i=0; i<times; i++){
            scores[i] = (scores[2*i]+scores[2*i+1]) % 10;
        }
        if (len&1){
            scores[times] = scores[len-1];
            len += 1;
        }
        len /= 2;
    }
    if (scores[0]&1){
        printf("I'm a winner!");
    }
    else {
        printf("You're the winner?");
    }
}