# include <iostream>
# include <vector>
# include <unordered_set>
using namespace std;
using llong = long long;

void solve();

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;

    while (t--){
        solve();
    }
}

int count(int x){
    int res = 0;

    while (x){
        res += x&1;
        x >>= 1;
    }

    return res;
}

void solve(){
    int n, m, k;    cin >> n >> m >> k;
    vector<int> colors(n+1);
    vector<pair<int, int>> edges;
    edges.reserve(m);

    vector<vector<llong>> dp(1<<k, vector<llong>(n+1));

    for (int i=1; i<=n; ++i){
        int c;  cin >> c;
        colors[i] = --c;

        dp[1<<c][i] = 1;
    }

    for (int i=0; i<m; ++i){
        int x, y;   cin >> x >> y;
        edges.push_back({x, y});
    }

    llong res = 0;

    for (int i=1; i<=k; ++i){
        for (pair<int, int>& edge : edges){
            int x = edge.first, y = edge.second;
            int cx = colors[x], cy = colors[y];

            for (int mask = 1; mask<(1<<k); ++mask){
                if (count(mask) != i)
                    continue;
                if (mask&(1<<cy));
                else {
                    dp[mask + (1<<cy)][y] += dp[mask][x];
                }

                if (mask&(1<<cx));
                else{
                    dp[mask + (1<<cx)][x] += dp[mask][y];
                }
            }
        }
    }

    for (int mask=1; mask<(1<<k); ++mask){
        if (count(mask) == 1)
            continue;
        for (int x=1; x<=n; ++x){
            res += dp[mask][x];
        }
    }

    cout << res << '\n';
}