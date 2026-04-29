# include <vector>
# include <queue>
# include <unordered_map>
using namespace std;

vector<int> solution(vector<int> nodes, vector<vector<int>> edgeInit) {
    int n = nodes.size();
    unordered_map<int, int> mapping;
    for (int i=0; i<n; i++){
        mapping[nodes[i]] = i;
    }
    
    vector<vector<int>> edges(n, vector<int>(0));
    for (vector<int>& edge : edgeInit){
        int u = edge[0], v = edge[1];
        u = mapping[u], v = mapping[v];
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    
    vector<bool> visited(n, false);
    vector<vector<bool>> isHolTree;
    
    
    for (int i=0; i<n; i++){
        if (visited[i])
            continue;
        queue<int> q;
        visited[i] = true;
        q.push(i);
        vector<bool> isHol;
        while (q.size()){
            int x = q.front();  q.pop();
            isHol.push_back((nodes[x]&1) == (edges[x].size()&1));
            
            for (int nx : edges[x]){
                if (visited[nx])
                    continue;
                visited[nx] = true;
                q.push(nx);
            }
        }
        isHolTree.push_back(isHol);
    }
    
    int holTreeCount = 0, rHolTreeCount = 0;
    
    for (vector<bool>& holTree : isHolTree){
        int holCount = 0, rHolCount = 0;
        for (bool node : holTree){
            if (node){
                ++holCount;
            }
            else {
                ++rHolCount;
            }
        }
        if (holCount == 1){
            ++holTreeCount;
        }
        if (rHolCount == 1){
            ++rHolTreeCount;
        }
    }
    
    return {holTreeCount, rHolTreeCount};
}