# include <stdio.h>
# include <string.h>

char a[10005];
char b[10005];
int ans[10005] = {0};

int strsum(char a[], char b[], int len_a, int len_b){
    int i, diff=len_a-len_b;
    for (i=len_a-1; i>=0; i--)
        ans[i+1] = a[i];
    for (i=len_b-1; i>=0; i--)
        ans[i+diff+1] += b[i];
    for (i=len_a-1; i>=0; i--){
        if (ans[i+1]>9){
            ans[i] += 1;
            ans[i+1] -= 10;
        }
    }
}

int main(void){
    scanf("%s", a);
    scanf("%s", b);
    int len_a = strlen(a);
    int len_b = strlen(b);
    int i, len = len_a>=len_b ? len_a : len_b;
    for (i=0; i<len_a; i++)
        a[i] -= '0';
    for (i=0; i<len_b; i++)
        b[i] -= '0';
    if (len_a>=len_b)
        strsum(a, b, len_a, len_b);
    else
        strsum(b, a, len_b, len_a);
    for (i=0; i<len+1; i++){
        if (i==0 && ans[i]==0)
            continue;
        printf("%d", ans[i]);
    }
    printf("\n");
}