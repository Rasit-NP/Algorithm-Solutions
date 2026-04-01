# include <iostream>
# include <vector>
# include <queue>
# include <climits>
# define MAX 998'244'353
typedef long long llong;
using namespace std;

vector<vector<pair<llong, llong>>> edges;
vector<int> visited;
queue<int> q;
vector<pair<llong, llong>> distances;

llong gcd(llong a, llong b){
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

llong pow(llong a, int x){
    llong res = 1;
    a %= MAX;
    llong bias = a;
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

llong restruct(pair<llong, llong>& input){
    llong dist = input.first, cnt = input.second;
    llong g;
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
    edges.assign(n+1, vector<pair<llong, llong>>(0));
    visited.assign(n+1, INT_MAX);
    distances.assign(n+1, {0, 0});

    for (int i=0; i<m; i++){
        int u, v, c;    cin >> u >> v >> c;
        edges[u].push_back({v, c});
        edges[v].push_back({u, c});
    }

    q.push(1);
    distances[1] = {0L, 1L};
    visited[1] = 0;

    while (q.size()){
        int x = q.front();  q.pop();
        for (const auto& [nx, c] : edges[x]){
            if (visited[x] + 1 > visited[nx]){
                continue;
            }
            distances[nx].first += distances[x].first + c * distances[x].second;
            distances[nx].second += distances[x].second;
            distances[nx].first %= MAX;
            distances[nx].second %= MAX;
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