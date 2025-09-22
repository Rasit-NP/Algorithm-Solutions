#include <stdio.h>

int main(){
    long n;
    long digit = 1;
    long count[10] = {0};
    int compare;
    scanf("%ld", &n);

    while (digit <= n){
        if (digit>1){
            compare = (n/digit)%10;
        }
        else if (digit == 1){
            compare = (n % 10);
        }
        for (int i=0; i<10; i++){
            count[i] += (n/(digit*10)) * digit;
            if (i==0){
                if (digit*10 > n){
                    continue;
                }
                else {
                    if (compare == 0){
                        count[i] += (n%digit) + 1;
                    }
                    else {
                        count[i] += digit;
                    }
                }
            }
            else if (0<i & i < compare){
                count[i] += digit;
            }
            else if (i == compare){
                count[i] += (n%digit) + 1;
            }
        }
        count[0] -= digit/10;
        digit *= 10;
    }
    for (int i=0; i<9; i++){
        printf("%d ", count[i]);
    }
    printf("%d", count[9]);

    return 0;
}