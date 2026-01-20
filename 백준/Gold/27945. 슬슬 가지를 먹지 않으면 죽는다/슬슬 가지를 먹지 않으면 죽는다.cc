# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> edges;
vector<int> parents;

void init(void){
    cin >> n >> m;
    parents.assign(n+1, 0);
    for (int i=1; i<=n; i++){
        parents[i] = i;
    }
    for (int i=0; i<m; i++){
        int u, v, t;    cin >> u >> v >> t;
        edges.push_back({t, u, v});
    }
    sort(edges.begin(), edges.end());
}

int find(int x){
    int a = x;
    while (parents[a] != a){
        parents[a] = parents[parents[a]];
        a = parents[a];
    }
    parents[x] = a;
    return parents[x];
}

void mst(void){
    int cnt = 1;
    for (vector<int> edge : edges){
        if (cnt == n)    break;
        int t = edge[0], u = edge[1], v = edge[2];
        if (t != cnt){
            cout << cnt << '\n';
            return;
        }
        int fu = find(u), fv = find(v);
        if (fu == fv){
            continue;
        }
        parents[fu] = fv;
        cnt++;
    }
    cout << cnt << '\n';
    return;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    init();
    mst();
}