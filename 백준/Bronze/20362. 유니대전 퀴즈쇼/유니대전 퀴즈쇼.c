# include <stdio.h>
# include <string.h>

char chat[1000][2][12];

int main(void){
    int n, cand;
    int count = 0;
    char congrat[12];
    char ans[12];
    int ret = 0;
    scanf("%d %s", &n, congrat);
    for (int i=0; i<n; i++){
        scanf("%s %s", chat[i][0], chat[i][1]);
        if (!strcmp(chat[i][0], congrat)){
            strcpy(ans, chat[i][1]);
            cand = count;
        }
        count += 1;
    }
    for (int i=0; i<cand; i++){
        if (!strcmp(chat[i][1], ans)){
            ret += 1;
        }
    }
    printf("%d", ret);
}