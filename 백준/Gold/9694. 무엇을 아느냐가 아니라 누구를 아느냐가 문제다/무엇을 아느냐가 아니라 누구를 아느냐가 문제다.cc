# include <iostream>
# include <vector>
# include <queue>
# include <stack>
# include <climits>
using namespace std;

vector<int> visited;
vector<vector<pair<int, int>>> edges;
stack<int> route;

void run(int& tc){
    int n, m;   cin >> n >> m;

    visited.assign(m, INT_MAX);
    visited[0] = 0;

    edges.assign(m, vector<pair<int, int>>(0));
    
    for (int i=0; i<n; i++){
        int x, y, z;    cin >> x >> y >> z;
        edges[x].push_back({y, z});
        edges[y].push_back({x, z});
    }

    priority_queue<pair<int, int>> heap;
    heap.push({0, 0});
    while (heap.size()){
        auto [t, now] = heap.top(); heap.pop();
        t *= -1;

        if (t > visited[now]){
            continue;
        }

        for (const auto& [next, dt] : edges[now]){
            int nt = t + dt;
            if (visited[next] > nt){
                visited[next] = nt;
                heap.push({-nt, next});
            }
        }
    }

    cout << "Case #" << tc << ":";

    if (visited[m-1] == INT_MAX){
        cout << " -1";
    }
    else {
        int x = m-1;
        while (x != 0){
            for (const auto& [nx, dt] : edges[x]){
                if (visited[nx] + dt == visited[x]){
                    route.push(x);
                    x = nx;
                    break;
                }
            }
        }
        route.push(0);
        while (route.size()){
            cout << ' ' << route.top(); route.pop();
        }
    }
    cout << '\n';
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;
    for (int tc=1; tc<=t; tc++){
        run(tc);
    }
}