# include <stdio.h>

int cnt = 0;

int swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    cnt += 1;
    return 0;
}

int main(void){
    int p;
    int height[20];
    scanf("%d", &p);
    for (int tc=0; tc<p; tc++){
        int t, i, j;
        cnt = 0;
        scanf("%d", &t);
        for (i=0; i<20; i++)
            scanf("%d", height+i);
        for (i=1; i<20; i++){
            for (j=i; j>0; j--){
                if (height[j]<height[j-1])
                    swap(height+j, height+j-1);
                else
                    break;
            }
        }
        printf("%d %d\n", t, cnt);
    }
}