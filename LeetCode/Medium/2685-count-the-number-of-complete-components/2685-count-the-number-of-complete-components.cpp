# include <vector>
# include <algorithm>
using namespace std;

class Solution {
private:
    int n;
    vector<vector<int>> edges;
    vector<int> visited;
    vector<vector<int>> clusters;

    void dfs(int x){
        sort(edges[x].begin(), edges[x].end());
        vector<int>& cluster = clusters.back();
        for (int nx : edges[x]){
            if (visited[nx] == 0){
                visited[nx] = 1;
                cluster.emplace_back(nx);
                dfs(nx);
            }
        }
    }

    bool check(vector<int>& cluster){
        int len = cluster.size();
        for (int x : cluster){
            if (edges[x].size() != len-1){
                return false;
            }
        }
        return true;
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        this->n = n;
        this->edges.assign(n, vector<int>(0));
        visited.assign(n, 0);

        for (vector<int>& edge : edges){
            int u = edge[0], v = edge[1];
            this->edges[u].emplace_back(v);
            this->edges[v].emplace_back(u);
        }

        for (int i=0; i<n; i++){
            if (visited[i] == 0){
                visited[i] = 1;
                clusters.push_back({i});
                dfs(i);
            }
        }

        int res = 0;

        for (vector<int>& cluster : clusters){
            res += check(cluster);
        }

        return res;
    }
};