# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int main(void){
    int t, tc=0;
    scanf("%d", &t);
    for (; tc<t; tc++){
        char num1[1000005], num2[1000005];
        scanf("%s %s", num1, num2);
        int len = strlen(num1);
        int cnt1[2]={0, 0}, cnt2[2] = {0, 0};
        int error = 0, ans = 0;
        for (int i=0; i<len; i++){
            if (num1[i] != num2[i])
                error += 1;
            if (num1[i] == '0')
                cnt1[0] += 1;
            else
                cnt1[1] += 1;
            if (num2[i] == '0')
                cnt2[0] += 1;
            else
                cnt2[1] += 1;
        }
        int diff = abs(cnt1[1]-cnt2[1]);
        ans += diff + (error - diff)/2;
        printf("%d\n", ans);
    }
}