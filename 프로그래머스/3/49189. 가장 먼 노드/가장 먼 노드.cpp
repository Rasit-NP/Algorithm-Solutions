# include <string>
# include <vector>
# include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    queue<int> q;
    vector<int> visited(n+1, 30'000);
    
    vector<vector<int>> edges(n+1, vector<int>(0));
    
    for (vector<int>& data : edge){
        int u = data[0], v = data[1];
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    
    visited[1] = 0;
    q.push(1);
    
    int dist = 0;
    int cnt = 0;
    
    while (q.size()){
        int x = q.front();  q.pop();
        
        for (int nx : edges[x]){
            if (visited[x] + 1 < visited[nx]){
                visited[nx] = visited[x] + 1;
                q.push(nx);
            }
        }
    }
    
    for (int i=1; i<=n; i++){
        if (visited[i] == 30'000){
            continue;
        }
        if (visited[i] > dist){
            dist = visited[i];
            cnt = 1;
        }
        else if (visited[i] == dist){
            ++cnt;
        }
    }
    
    return cnt;
}