# include <iostream>
# include <vector>
# include <queue>
# include <unordered_set>
using namespace std;

int n;
vector<pair<int, int>> edges;
vector<vector<int>> edge_list;
vector<int> energies;

struct Cycle{
    bool isCycle = false;
    bool finish = false;
    unordered_set<int> nodes;
};

Cycle bellman_ford(){
    Cycle cycle;
    vector<int> visited(n+1, -500);
    visited[1] = 100;
    for (int i=0; i<n-1; i++){
        for (pair<int, int> edge : edges){
            int x = edge.first, nx = edge.second;
            if (visited[x] + energies[nx] < 0)
                continue;
            if (visited[nx] < visited[x] + energies[nx]){
                visited[nx] = visited[x] + energies[nx];
            }
        }
    }

    for (pair<int, int> edge : edges){
        int x = edge.first, nx = edge.second;
        if (visited[x] + energies[nx] < 0)
            continue;
        if (visited[nx] < visited[x] + energies[nx]){
            cycle.isCycle = true;
            cycle.nodes.insert(nx);
        }
    }

    if (visited[n] > 0){
        cycle.finish = true;
    }
    return cycle;
}

bool bfs(unordered_set<int> cycle){
    queue<int> q;
    vector<bool> visited(n+1, false);
    for (int node : cycle){
        q.push(node);
        visited[node] = true;
    }
    while (q.size()){
        int x = q.front();  q.pop();
        if (x == n){
            return true;
        }
        for (int nx : edge_list[x]){
            if (visited[nx])
                continue;
            q.push(nx);
            visited[nx] = true;
        }
    }
    return false;
}

void run(int n){
    edges.clear();
    energies.assign(n+1, 0);
    edge_list.assign(n+1, vector<int>(0));
    for (int i=1; i<=n; i++){
        int cnt_edge;   cin >> energies[i] >> cnt_edge;
        for (int j=0; j<cnt_edge; j++){
            int room;   cin >> room;
            edges.push_back({i, room});
            edge_list[i].push_back(room);
        }
    }
    Cycle cycle = bellman_ford();
    if (cycle.finish){
        cout << "winnable\n";
    }
    else if (cycle.isCycle){
        if (bfs(cycle.nodes)){
            cout << "winnable\n";
        }
        else{
            cout << "hopeless\n";
        }
    }
    else {
        cout << "hopeless\n";
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    while (cin >> n){
        if (n == -1)    break;
        run(n);
    }
}