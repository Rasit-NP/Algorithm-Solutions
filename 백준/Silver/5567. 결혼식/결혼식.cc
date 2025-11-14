# include <iostream>
# include <queue>
# include <vector>
using namespace std;

int main(){
    int n, m, i=0;
    scanf("%d", &n);
    scanf("%d", &m);
    vector<vector<int>> edges(n+1);
    vector<int> visited(n+1);
    for (; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (i=0; i<=n; i++)
        visited[i] = -1;
    queue<int> q;
    q.push(1);
    visited[1] = 0;
    int count = 0;
    while (q.size()){
        int x = q.front();
        q.pop();
        if (visited[x] >= 2)
            continue;
        for (int i=0; i<edges[x].size(); i++){
            int nx = edges[x][i];
            if (visited[nx] == -1){
                count++;
                visited[nx] = visited[x] + 1;
                q.push(nx);
            }
        }
    }
    printf("%d\n", count);
    return 0;
}