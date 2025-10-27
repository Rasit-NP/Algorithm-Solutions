# include <stdio.h>
# include <string.h>
# define MAX 10000

int bridge[MAX] = {0};
int queue[MAX] = {0};
int visited[MAX];
int n;

int init(int visited[]){
    for (int i=0; i<n; i++){
        visited[i] = (1<<30);
    }
    return 0;
}

int run(int a, int b){
    int ans = -1, head = 0, size = 0, idx;
    a -= 1, b -= 1;
    queue[head] = a;
    visited[a] = 0;
    size += 1;
    while (size){
        int x = queue[head++];
        size -= 1;
        if (x==b){
            ans = visited[b];
            break;
        }
        int dx = bridge[x];
        int nx = x+dx;
        while (nx < n){
            if (visited[nx] > visited[x] + 1){
                visited[nx] = visited[x] + 1;
                idx = head + (size++);
                idx = idx==n ? 0 : idx;
                queue[idx] = nx;
            }
            nx += dx;
        }
        nx = x-dx;
        while (nx >= 0){
            if (visited[nx] > visited[x] + 1){
                visited[nx] = visited[x] + 1;
                idx = head + (size++);
                idx = idx==-1 ? n-1 : idx;
                queue[idx] = nx;
            }
            nx -= dx;
        }
    }
    printf("%d", ans);
    return 0;
}

int main(void){
    int i, a, b;
    scanf("%d", &n);
    init(visited);
    for (i=0; i<n; i++){
        scanf("%d", &bridge[i]);
    }
    scanf("%d %d", &a, &b);
    run(a, b);
    return 0;
}