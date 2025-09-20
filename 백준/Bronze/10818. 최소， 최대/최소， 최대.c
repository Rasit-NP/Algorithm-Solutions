#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int min=1000001, max=-1000001;
    for (int i=0; i<n; i++){
        int num;
        scanf("%d", &num);
        if (num>max){
            max = num;
        }
        if (num<min){
            min = num;
        }
    }
    printf("%d %d", min, max);
}    
