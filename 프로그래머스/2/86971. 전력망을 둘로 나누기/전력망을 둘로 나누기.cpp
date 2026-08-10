# include <vector>
# include <queue>
# include <algorithm>
using namespace std;

vector<vector<int>> edges;

int getChilds(int r, vector<int>& visited){
    int res = 1;
    queue<int> q;
    q.push(r);
    
    while (q.size()){
        int x = q.front();  q.pop();
        for (int nx : edges[x]){
            if (!visited[nx]){
                ++res;
                q.push(nx);
                visited[nx] = 1;
            }
        }
    }
    
    return res;
}

int solution(int n, vector<vector<int>> wires) {
    edges.assign(n+1, vector<int>(0));
    for (const auto& wire : wires){
        int u = wire[0], v = wire[1];
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }
    
    int res = 2*n;
    
    for (const auto& roots : wires){
        int ra = roots[0], rb = roots[1];
        vector<int> visited(n+1, 0);
        visited[ra] = 1, visited[rb] = 1;
        
        int sizeA = getChilds(ra, visited);
        int sizeB = getChilds(rb, visited);
        
        res = min(res, abs(sizeA-sizeB));
    }
    return res;
}