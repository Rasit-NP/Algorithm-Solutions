# include <stdio.h>
# include <string.h>

int main(void){
    int n, cnt=0;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        char word[105];
        scanf("%s", word);
        int len = strlen(word);
        int save[26] = {0};
        int state = 1;
        for (int j=0; j<len; j++){
            int now = save[word[j]-97];
            if (now == 0){
                save[word[j]-97] = 1;
                if (j > 0)
                    save[word[j-1]-97] = 2;
            }
            else if (now == 1){
                continue;
            }
            else if (now == 2){
                state = 0;
                break;
            }
        }
        if (state)
            cnt += 1;
    }
    printf("%d\n", cnt);
}