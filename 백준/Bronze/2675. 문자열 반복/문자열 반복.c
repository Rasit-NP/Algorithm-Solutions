#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d", &t);

    for (int tc=0; tc<t; tc++){
        int r;
        char s[21];
        scanf("%d %s", &r, s);
        int len = strlen(s);

        for (int i=0; i<len; i++){
            for (int j=0; j<r; j++){
                printf("%c", s[i]);
            }
        }
        printf("\n");
    }
    return 0;
}