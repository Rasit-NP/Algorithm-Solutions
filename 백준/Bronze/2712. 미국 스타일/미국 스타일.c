# include <stdio.h>
# include <string.h>
# include <math.h>

int main(void){
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++){
        double num;
        char unit[3];
        scanf("%lf %s", &num, unit);
        if (!strcmp(unit, "kg")){
            printf("%.4lf lb\n", round(num*(2.2046)*10000)/10000);
        }
        else if (!strcmp(unit, "l")){
            printf("%.4lf g\n", round(num*(0.2642)*10000)/10000);
        }
        else if (!strcmp(unit, "lb")){
            printf("%.4lf kg\n", round(num*(0.4536)*10000)/10000);
        }
        else if (!strcmp(unit, "g")){
            printf("%.4lf l\n", round(num*(3.7854)*10000)/10000);
        }
    }
}