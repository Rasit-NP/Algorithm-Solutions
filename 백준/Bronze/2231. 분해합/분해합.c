#include <stdio.h>

int main() {
    int n;
    int ans=0;
    scanf("%d", &n);
    for (int i=1; i<n; i++){
        int x = i;
        int sum = x;
        while(x>0){
            sum += x%10;
            x /= 10;
        }
        if (sum==n){
            ans = i;
            break;
        }
    }
    printf("%d", ans);
}    
