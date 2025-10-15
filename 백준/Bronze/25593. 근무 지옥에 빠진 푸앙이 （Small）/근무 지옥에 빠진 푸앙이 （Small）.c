# include <stdio.h>
# include <string.h>
# define MAX_NAME 25
# define MAX_POPULATION 100

int find(char *);
int check(void);

typedef struct {
    char name[MAX_NAME];
    int time;
} Person;

Person people[MAX_POPULATION];
int cnt_name = 0;
int times[4] = {4, 6, 4, 10};

int main(void){
    int n, week=0;
    scanf("%d", &n);
    for (; week<n; week++){
        int time=0;
        for (; time<4; time++){
            int day=0;
            for (; day<7; day++){
                char name[MAX_NAME];
                scanf("%s", name);
                if (*name=='-')
                continue;
                int idx = find(name);
                people[idx].time += times[time];
            }
        }
    }
    check();
}

int find(char *target){
    for (int i=0; i<cnt_name; i++){
        if (!strcmp(people[i].name, target)){
            return i;
        }
    }
    strcpy(people[cnt_name].name, target);
    return cnt_name++;
}

int check(void){
    int min = 10000000, max = 0;
    for (int i=0; i<cnt_name; i++){
        int t = people[i].time;
        if (t<min)
            min = t;
        if (t>max)
            max = t;
    }
    if (max-min <= 12)
        printf("Yes\n");
    else
        printf("No\n");
}