# include <stdio.h>

int main(void){
    int burgers[3] = {0};
    int beverages[2] = {0};
    int i, j;
    for (i=0; i<3; i++){
        scanf("%d", &burgers[i]);
    }
    for (i=0; i<2; i++){
        scanf("%d", &beverages[i]);
    }
    int min = 5000;
    for (i=0; i<3; i++){
        for (j=0; j<2; j++){
            int sum = burgers[i]+beverages[j];
            min = min>sum ? sum : min;
        }
    }
    printf("%d\n", min-50);
}