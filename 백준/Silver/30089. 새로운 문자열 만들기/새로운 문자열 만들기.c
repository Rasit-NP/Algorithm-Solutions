#include <stdio.h>
#include <string.h>

int main(void){
    int t, tc;
    scanf("%d", &t);
    for (tc=0; tc<t; tc++){
        char word[25], ans[45];
        scanf("%s", word);
        int i, j, k, len = strlen(word);
        for (i=0; i<len; i++){
            int check = 1;
            for (j=0; j<len-i; j++){
                if (word[j+i]==word[len-j-1])
                    continue;
                else {
                    check = 0;
                    break;
                }
            }
            if (check){
                k = i;
                break;
            }
        }
        memset(ans, 0, sizeof(ans));
        strcpy(ans, word);
        for (i=0; i<k; i++){
            ans[len + i] = word[k-i-1];
        }
        printf("%s\n", ans);
    }
}