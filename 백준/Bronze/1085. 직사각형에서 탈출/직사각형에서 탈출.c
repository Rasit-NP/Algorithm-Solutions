#include <stdio.h>

int main() {
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    int d1, d2, d3, d4;
    int dists[4] = {x, y, w-x, h-y};
    int min = 1010;
    for (int i=0; i<4; i++){
        if (dists[i]<min){
            min = dists[i];
        }
    }
    printf("%d", min);
    return 0;
}