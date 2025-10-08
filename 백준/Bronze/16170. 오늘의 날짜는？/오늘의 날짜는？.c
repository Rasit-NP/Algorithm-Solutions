# include <stdio.h>
# include <time.h>

int main(void){
    time_t timer = time(NULL);
    struct tm* t = gmtime(&timer);
    printf("%d\n%d\n%d",
        t->tm_year+1900,
        t->tm_mon+1,
        t->tm_mday);
}