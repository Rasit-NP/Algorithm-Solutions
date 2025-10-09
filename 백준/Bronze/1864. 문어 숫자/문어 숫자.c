# include <stdio.h>
# include <string.h>
# include <math.h>

int main(){
    while (1){
        char oct[10];
        scanf("%s", oct);
        if (oct[0] == '#')
            break;
        int len = strlen(oct);
        int ans=0;
        for (int i=0; i<len; i++){
            char now = oct[len-i-1];
            int base = pow(8, i);
            if (now == '-')
                ans += base * 0;
            else if (now == '\\')
                ans += base * 1;
            else if (now == '(')
                ans += base * 2;
            else if (now == '@')
                ans += base * 3;
            else if (now == '?')
                ans += base * 4;
            else if (now == '>')
                ans += base * 5;
            else if (now == '&')
                ans += base * 6;
            else if (now == '%')
                ans += base * 7;
            else
                ans -= base;
        }
        printf("%d\n", ans);
    }
}