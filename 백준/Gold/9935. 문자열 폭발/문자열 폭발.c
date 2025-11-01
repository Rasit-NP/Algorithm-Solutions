# include <stdio.h>
# include <string.h>

char word[1000005];
char stack[1000005];
int len_bomb;

char check(char bomb[], int idx){
    for (int i=0; i<len_bomb; i++){
        if (bomb[i] != stack[idx-len_bomb+i])
            return 0;
    }
    return 1;
}

int main(void){
    char bomb[40];
    scanf("%s", word);
    scanf("%s", bomb);
    int len = strlen(word);
    int idx = 0, i;
    len_bomb = strlen(bomb);
    char last_bomb = bomb[len_bomb-1];
    for (i=0; i<len; i++){
        stack[idx++] = word[i];
        if (word[i] == last_bomb && idx >= len_bomb){
            if (check(bomb, idx))
                idx -= len_bomb;
        }
    }
    if (idx > 0){
        for (i=0; i<idx; i++){
            printf("%c", stack[i]);
        }
        printf("\n");
    }
    else    printf("FRULA\n");
}