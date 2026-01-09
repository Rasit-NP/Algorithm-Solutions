# include <iostream>
# include <vector>
using namespace std;

int n, r, q;
vector<int> tree;
vector<vector<int>> edges;
vector<int> visited;
vector<int> childrens;

void init(void){
    cin >> n >> r >> q;
    edges.assign(n+1, vector<int>(0));
    visited.assign(n+1, 0);
    childrens.assign(n+1, 1);
    for (int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    visited[r] = 1;
}

void dfs(int x){
    for (int nx : edges[x]){
        if (!visited[nx]){
            visited[nx] = 1;
            dfs(nx);
            childrens[x] += childrens[nx];
        }
    }
}
void query(void){
    int u;  cin >> u;
    cout << childrens[u] << '\n';
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    init();
    dfs(r);
    for (int i=0; i<q; i++){
        query();
    }
}