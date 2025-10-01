# include <stdio.h>

int main(void){
    int n;
    int data[26] = {0};
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        char name[32];
        scanf("%s", name);
        data[(int) (name[0])-97] += 1;
    }
    int count=0;
    for (int i=0; i<26; i++){
        if (data[i] >= 5){
            count += 1;
            printf("%c", i+97);
        }
    }
    if (!count){
        printf("PREDAJA");
    }
    printf("\n");
}