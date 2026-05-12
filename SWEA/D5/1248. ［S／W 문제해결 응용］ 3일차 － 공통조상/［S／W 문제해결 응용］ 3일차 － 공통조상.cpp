# include <iostream>
# include <vector>
# include <cmath>
# include <algorithm>
using namespace std;

int v, e, a, b;
vector<vector<int>> edges, parents;
vector<int> height;
vector<int> treeSize;

int dfs(int x);

void solve(int tc){
    cin >> v >> e >> a >> b;
    int MAX = log2(v);
    edges.assign(v+1, vector<int>(0));
    parents.assign(v+1, vector<int>(MAX+1, 0));
    height.assign(v+1, -1);
    treeSize.assign(v+1, -1);
    for (int i=0; i<e; i++){
        int p, c;   cin >> p >> c;
        edges[p].push_back(c);
        parents[c][0] = p;
    }

    height[1] = 0;
    dfs(1);

    for (int top=0; top<MAX; top++){
        for (int x=1; x<=v; x++){
            int nx = parents[x][top];
            if (nx && parents[nx][top]){
                parents[x][top+1] = parents[nx][top];
            }
        }
    }

    int ha = height[a], hb = height[b];
    if (ha > hb){
        swap(a, b);
        swap(ha, hb);
    }

    int diff = hb - ha;

    for (int i=0; (1<<i)<=diff; i++){
        if (diff & (1<<i)){
            b = parents[b][i];
        }
    }

    while(a != b){
        int i;
        for (i=0; i<=MAX; i++){
            if (parents[a][0] == parents[b][0]){
                a = parents[a][0];
                b = parents[b][0];
                break;
            }
            if (parents[a][i] == parents[b][i]){
                a = parents[a][i-1];
                b = parents[b][i-1];
                ha = height[a];
                break;
            }
            if ((1<<i) == ha){
                a = parents[a][i];
                b = parents[b][i];
                ha = height[a];
            }
        }
    }

    cout << "#" << tc << ' ' << a << ' ' << treeSize[a] << '\n';

}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;
    for (int tc=1; tc<=t; tc++){
        solve(tc);
    }
}

int dfs(int x){
    int nextHeight = height[x] + 1;
    int sum = 0;
    for (int nx : edges[x]){
        height[nx] = nextHeight;
        sum += dfs(nx);
    }
    treeSize[x] = sum + 1;
    return sum + 1;
}