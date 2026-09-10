# include <vector>
# include <climits>
# include <queue>
# include <algorithm>
using namespace std;
using pii = pair<int, int>;

vector<vector<pii>> edges;

void dijkstra(vector<int>& visited, int s){
    priority_queue<pii> pq;
    visited[s] = 0;
    pq.emplace(0, s);
    
    while (pq.size()){
        auto [c, x] = pq.top();   pq.pop();
        c *= -1;
        
        if (c > visited[x])
            continue;
        
        for (const auto& [nx, dc] : edges[x]){
            int nc = c + dc;
            if (nc < visited[nx]){
                visited[nx] = nc;
                pq.emplace(-nc, nx);
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int res = INT_MAX;
    
    vector<int> fromS(n+1, INT_MAX);
    vector<int> fromA(n+1, INT_MAX);
    vector<int> fromB(n+1, INT_MAX);
    
    edges.assign(n+1, vector<pii>(0));
    
    for (vector<int> fare : fares){
        int c = fare[0], d = fare[1], f = fare[2];
        edges[c].emplace_back(d, f);
        edges[d].emplace_back(c, f);
    }
    
    dijkstra(fromS, s);
    dijkstra(fromA, a);
    dijkstra(fromB, b);
    
    for (int i=1; i<=n; ++i){
        res = min(res, fromS[i] + fromA[i] + fromB[i]);
    }
    
    return res;
}