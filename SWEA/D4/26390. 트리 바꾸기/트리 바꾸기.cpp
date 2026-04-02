# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
using namespace std;


void run(void){
    int n;  cin >> n;
    vector<int> dp(n+1, 0);
    vector<vector<int>> edges(n+1, vector<int>(0));
    vector<bool> visited(n+1, false);

    for (int i=0; i<n-1; i++){
        int u, v;   cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    long long res = 0;
    queue<int> q;

    q.push(1);
    visited[1] = true;

    while (q.size()){
        int x = q.front(); q.pop();
        int cnt = 0;

        for (int& nx : edges[x]){
            if (visited[nx]){
                continue;
            }
            q.push(nx);
            visited[nx] = true;

            cnt++;
        }
        if (x == 1){
            res += max(cnt-2, 0);
        }
        else {
            res += max(cnt-1, 0);
        }
    }

    cout << res << '\n';
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int TC; cin >> TC;
    for (int t=1; t<=TC; t++){
        run();
    }
}