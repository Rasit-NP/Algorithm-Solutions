#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    for (int tc=0; tc<t; tc++){
        int count = 0;
        int n;
        int fives = 5;
        scanf("%d", &n);
        while (fives<=n){
            count += n/fives;
            fives *= 5;
        }
        printf("%d\n", count);
    }
    return 0;
}