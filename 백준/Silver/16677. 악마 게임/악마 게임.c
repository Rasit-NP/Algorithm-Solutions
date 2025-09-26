# include <stdio.h>
# include <string.h>

int main()
{
    int n;
    double max=0;
    char m[101];
    char ans[101];
    scanf("%s", m);
    scanf("%d", &n);
    int len_m = strlen(m);
    for (int i=0; i<n; i++){
        char w[101];
        int g, len_w;
        scanf("%s %d", w, &g);
        len_w = strlen(w);
        int idx=0;
        int state=0;
        for (int j=0; j<len_w; j++){
            if (w[j] == m[idx]){
                idx += 1;
                if (idx==len_m){
                    state = 1;
                     break;
                }
            }
            }
        if (state){
            double score = (double)g/(len_w-len_m);
            if (score > max){
                max = score;
                strcpy(ans, w);
            }
        }
    }
    if (max > 0){
        printf("%s", ans);
    }
    else{
        printf("No Jam");
    }
    
    return 0;
}