# include <vector>
# include <queue>
# include <algorithm>
typedef long long llong;
using namespace std;

int MAX = 1'000'000'007;

class Solution {
private:
    int n;
    vector<vector<int>> edges;
    vector<int> visited;
    int bfs(void){
        queue<int> q;
        q.push(1);
        visited[1] = 0;

        int res = 0;
        
        while(q.size()){
            int x = q.front();  q.pop();

            for (int nx : edges[x]){
                if (visited[nx] == -1){
                    q.push(nx);
                    visited[nx] = visited[x] + 1;
                    res = max(res, visited[nx]);
                }
            }
        }

        return res;
    }

    llong comb(int n, int r){
        llong res = 1;
        for (int i=1; i<=r; i++){
            res *= (n-i+1);
            res /= i;
            res %= MAX;
        }
        return res;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& es) {
        n = es.size() + 1;
        edges.assign(n+1, vector<int>(0));
        visited.assign(n+1, -1);
        for (vector<int>& e : es){
            int u = e[0], v = e[1];
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        int k = bfs();

        llong res = 1;
        for (int i=0; i<k-1; i++){
            res <<= 1;
            res %= MAX;
        }

        return (int)res;
    }
};