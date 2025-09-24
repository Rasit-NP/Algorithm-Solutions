# include <stdio.h>

int main(){
    
    int n;
    int max=0;
    scanf("%d", &n);
    int count[101] = {0};
    int me, now;
    scanf("%d", &me);
    for (int i=1; i<n; i++){
        scanf("%d", &now);
        count[now] += 1;
        if (now > max){
            max = now;
        }
    }
    int lobby = 0;
    while (me <= max){
        if ((max-me) >= count[max]){
            me += count[max];
            lobby += count[max];
            count[max-1] += count[max];
            count[max] = 0;
            max -= 1;
        }
        else if ((max-me) < count[max]){
            int get = (max-me) + 1;
            lobby += get;
            count[max] -= get;
            me += get;
        }
    }
    printf("%d", lobby);
    return 0;
}