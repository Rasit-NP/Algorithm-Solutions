# include <iostream>
# include <vector>
# include <queue>
# include <climits>
using namespace std;

int n;
vector<vector<int>> edges;

int bfs(int j){
    queue<int> q;
    vector<int> visited(n+1, INT_MAX);
    int res = 0;
    q.push(j);
    visited[j] = 0;
    while (q.size()){
        int x = q.front();  q.pop();
        for (const int& nx : edges[x]){
            if (visited[nx] == INT_MAX){
                visited[nx] = visited[x] + 1;
                q.push(nx);
            }
        }
    }
    for (int i=1; i<=n; i++){
        res = max(res, visited[i]);
    }
    return res;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n;
    edges.assign(n+1, vector<int>(0));

    while(true){
        int x, y;   cin >> x >> y;
        if (x == -1 && y == -1){
            break;
        }
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    int ans = INT_MAX;
    vector<int> candidates;

    for (int i=1; i<=n; i++){
        int cnt = bfs(i);
        if (cnt < ans){
            candidates.clear();
            ans = cnt;
            candidates.push_back(i);
        }
        else if (cnt == ans){
            candidates.push_back(i);
        }
    }

    cout << ans << ' ' << candidates.size() << '\n';
    for (const int& candidate : candidates){
        cout << candidate << ' ';
    }
}