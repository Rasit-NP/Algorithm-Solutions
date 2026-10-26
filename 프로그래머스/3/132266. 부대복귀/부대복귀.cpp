# include <vector>
# include <queue>
using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<vector<int>> edges(n+1, vector<int>(0));
    
    for (vector<int>& road : roads){
        int a = road[0], b = road[1];
        
        edges[a].emplace_back(b);
        edges[b].emplace_back(a);
    }
    
    vector<int> visited(n+1, -1);
    visited[destination] = 0;
    
    queue<int> q;
    q.push(destination);
    
    while (q.size()){
        int x = q.front();  q.pop();
        
        for (int nx : edges[x]){
            if (visited[nx] == -1){
                visited[nx] = visited[x] + 1;
                q.push(nx);
            }
        }
    }
    
    vector<int> res;
    res.reserve(sources.size());
    
    for (int source : sources){
        res.emplace_back(visited[source]);
    }
    
    return res;
}