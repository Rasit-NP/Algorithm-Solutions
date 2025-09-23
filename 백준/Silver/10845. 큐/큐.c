# include <stdio.h>
# include <string.h>
# define MAX 10001

int main(){
    int queue[MAX];
    int n;
    int size = 0;
    int front = 0, rear = 0;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        char cmd[10];
        scanf("%s", cmd);
        if (!strcmp(cmd, "push")){
            int x;
            scanf("%d", &x);
            queue[rear] = x;
            rear = (rear+1) % MAX;
            size += 1;
        }
        else if (!strcmp(cmd, "front")){
            if (size == 0){
                printf("%d\n", -1);
            }
            else{
                printf("%d\n", queue[front]);
            }
        }
        else if (!strcmp(cmd, "back")){
            if (size == 0){
                printf("%d\n", -1);
            }
            else{
                printf("%d\n", queue[(rear-1+MAX)%MAX]);
            }
        }
        else if (!strcmp(cmd, "size")){
            printf("%d\n", size);
        }
        else if (!strcmp(cmd, "pop")){
            if (size == 0){
                printf("%d\n", -1);
            }
            else{
                printf("%d\n", queue[front]);
                front = (front+1) % MAX;
                size -= 1;
            }
        }
        else if (!strcmp(cmd, "empty")){
            if (size == 0){
                printf("%d\n", 1);
            }
            else{
                printf("%d\n", 0);
            }
        }
    }
}