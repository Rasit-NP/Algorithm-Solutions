# include <stdio.h>
# include <string.h>

int count_w(char wolf[], int i){
    int cnt=0;
    while (wolf[i] == 'w'){
        cnt += 1;
        i += 1;
    }
    return cnt;
}

int compare(char wolf[], int i, int n){
    char cmp[4] = {'w', 'o', 'l', 'f'};
    for (int idx=0; idx<4; idx++){
        for (int j=0; j<n; j++){
            if (wolf[i+j+idx*n] != cmp[idx])
                return 0;
        }
    }
    return 1;
}

int main(void){
    char wolf[55];
    scanf("%s", wolf);
    int i, n, len = strlen(wolf);
    int ans = 1;
    for (i=0; i<len;){
        if (wolf[i]=='w')
            n = count_w(wolf, i);
        else {
            ans = 0;
            break;
        }
        if (!compare(wolf, i, n)){
            ans = 0;
            break;
        }
        i += 4*n;
    }
    printf("%d\n", ans);
}