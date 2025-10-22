# include <stdio.h>

int n;

int main(void){
    int state[4] = {0};
    long long range[4] = {0};
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        int idx;
        long long x, y;
        char d;
        scanf("%lld %lld %c", &x, &y, &d);
        if (d=='L'){
            idx = 0;
            if (state[idx] && x<range[idx]){
                range[idx] = x;
                continue;
            }
            if (!state[idx]){
                state[idx] = 1;
                range[idx] = x;
            }
        }
        if (d == 'R'){
            idx = 1;
            if (state[idx] && x>range[idx]){
                range[idx] = x;
                continue;
            }
            if (!state[idx]){
                state[idx] = 1;
                range[idx] = x;
            }
        }
        if (d == 'U'){
            idx = 2;
            if (state[idx] && y>range[idx]){
                range[idx] = y;
                continue;
            }
            if (!state[idx]){
                state[idx] = 1;
                range[idx] = y;
            }
        }
        if (d == 'D'){
            idx = 3;
            if (state[idx] && y<range[idx]){
                range[idx] = y;
                continue;
            }
            if (!state[idx]){
                state[idx] = 1;
                range[idx] = y;
            }
        }
    }
    for (int i=0; i<4; i++){
        if (!state[i]){
            printf("Infinity");
            return 0;
        }
    }
    printf("%lld\n", (range[0]-range[1]-1)*(range[3]-range[2]-1));
}