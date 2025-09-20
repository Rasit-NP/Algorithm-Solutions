#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int tc=0; tc<t; tc++){
        int h, w, n;
        scanf("%d %d %d", &h, &w, &n);
        int y, x;
        // 층, 호
        x = (n-1)/h;
        y = (n-1)-(x*h);
        x++;
        y++;
        printf("%d\n", 100*y+x);
    }    
}