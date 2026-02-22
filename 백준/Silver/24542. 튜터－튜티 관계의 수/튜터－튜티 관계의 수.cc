# include <iostream>
# include <vector>
using namespace std;

int n, m, cnt;
vector<vector<int>> edges;
vector<int> visited;

void dfs(int x){
    cnt++;
    for (int nx : edges[x]){
        if (visited[nx])    continue;
        visited[nx] = 1;
        dfs(nx);
    }
}

int main(void){

    cin >> n >> m;
    edges.assign(n+1, vector<int>(0));

    for (int i=0; i<m; i++){
        int u, v;   cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    visited.assign(n+1, 0);
    vector<int> node_cnt;

    for (int i=1; i<=n; i++){
        cnt = 0;

        if (visited[i]) continue;

        visited[i] = 1;
        dfs(i);

        node_cnt.push_back(cnt);
    }

    long long ans = 1;
    for (int c : node_cnt){
        ans *= c;
        ans %= 1000000007;
    }
    cout << ans;
}