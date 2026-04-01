# include <iostream>
# include <vector>
# include <queue>
# include <climits>
# define MAX 998'244'353
using namespace std;

vector<vector<pair<long long, long long>>> edges;
vector<int> visited;
queue<int> q;
vector<pair<int, int>> distances;

int gcd(int a, int b){
    if (a < b){
        swap(a, b);
    }
    int tmp;
    while (a%b){
        tmp = a%b;
        a = b;
        b = tmp;
    }
    return b;
}

long long pow(long long a, int x){
    long long res = 1;
    a %= MAX;
    long long bias = a;
    while(x){
        if (x&1){
            res *= bias;
        }
        bias *= bias;

        res %= MAX;
        bias %= MAX;

        x >>= 1;
    }
    return res;
}

long long restruct(pair<int, int>& input){
    input.first %= MAX;
    long long dist = input.first, cnt = input.second;
    int g;
    if (dist == 0 || cnt == 0){
        g = 1;
    }
    else{
        g = gcd(dist, cnt);
    }
    dist /= g;
    cnt /= g;

    return (dist * pow(cnt, MAX-2)) % MAX;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n, m;   cin >> n >> m;
    edges.assign(n+1, vector<pair<long long, long long>>(0));
    visited.assign(n+1, INT_MAX);
    distances.assign(n+1, {0, 0});

    for (int i=0; i<m; i++){
        int u, v, c;    cin >> u >> v >> c;
        edges[u].push_back({v, c});
        edges[v].push_back({u, c});
    }

    q.push(1);
    distances[1] = {0, 1};
    visited[1] = 0;

    while (q.size()){
        int x = q.front();  q.pop();
        for (const auto& [nx, c] : edges[x]){
            if (visited[x] + 1 > visited[nx]){
                continue;
            }
            distances[nx].first += (distances[x].first + c) * distances[x].second;
            distances[nx].second += distances[x].second;
            if (visited[nx] > visited[x] + 1){
                visited[nx] = visited[x] + 1;
                q.push(nx);
            }
        }
    }

    for (int i=2; i<=n; i++){
        cout << restruct(distances[i]) << '\n';
    }
}