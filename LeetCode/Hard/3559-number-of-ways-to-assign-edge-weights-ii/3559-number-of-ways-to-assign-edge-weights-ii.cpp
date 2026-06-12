# include <vector>
# include <queue>
# include <algorithm>
# include <unordered_map>
using namespace std;

class Solution {
private:
    int n;
    vector<vector<int>> edges;
    vector<vector<int>> parents;
    unordered_map<int, int> memo;
    vector<int> visited;
    vector<int> res;

    void bfs(void){
        queue<int> q;
        q.push(1);
        visited[1] = 0;

        while (q.size()){
            int x = q.front();  q.pop();
            for (int nx : edges[x]){
                if (visited[nx] != -1)
                    continue;
                visited[nx] = visited[x] + 1;
                parents[nx][0] = x;
                q.push(nx);
            }
        }
    }

    void connectAncestor(void){
        for (int deg=0; deg<17; deg++){
            for (int x=2; x<=n; x++){
                int p = parents[x][deg];
                if (p < 0){
                    continue;
                }
                int pp = parents[p][deg];
                if (pp < 0){
                    continue;
                }
                else {
                    parents[x][deg+1] = pp;
                }
            }
        }
    }

    int getLCA(int a, int b){
        if (visited[a] < visited[b]){
            swap(a, b);
        }

        int diff = visited[a] - visited[b];

        for (int i=0; diff; diff>>=1, i++){
            if (diff & 1){
                a = parents[a][i];
            }
        }

        while (a != b){
            for (int deg=17; deg>=0; --deg){
                if (deg && (parents[a][deg] == parents[b][deg])){
                    continue;
                }
                else if (deg == 0 && (parents[a][deg] == parents[b][deg])){
                    a = parents[a][deg];
                    b = parents[b][deg];
                }
                else if (parents[a][deg] != parents[b][deg]){
                    a = parents[a][deg];
                    b = parents[b][deg];
                }
            }
        }

        return a;
    }

    int solve(int u, int v){
        if (u == v){
            return 0;
        }
        int p = getLCA(u, v);
        int k = visited[u] + visited[v] - 2*visited[p];
        if (memo.find(k) != memo.end()){
            return memo[k];
        }
        int val = 1;
        for (int i=0; i<k-1; i++){
            val <<= 1;
            val %= 1'000'000'007;
        }

        memo[k] = val;

        return val;
    }
    
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& es, vector<vector<int>>& queries) {
        n = es.size() + 1;
        edges.assign(n+1, vector<int>(0));
        visited.assign(n+1, -1);
        parents.assign(n+1, vector<int>(18, -1));

        for (vector<int> e : es){
            int u = e[0], v = e[1];
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        bfs();
        connectAncestor();

        for (vector<int> query : queries){
            int u = query[0], v = query[1];
            res.push_back(solve(u, v));
        }

        return this->res;
    }
};