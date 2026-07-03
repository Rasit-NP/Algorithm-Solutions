# include <vector>
# include <queue>
# include <climits>
using namespace std;
typedef long long ll;

class Solution {
private:
    int n;
    ll k;
    vector<vector<pair<int, int>>> edges;

    int cal(int m){
        vector<ll> visited(n, LONG_LONG_MAX);
        priority_queue<pair<ll, int>> q;

        visited[0] = 0;
        q.emplace(0, 0);

        while (q.size()){
            pair<ll, int> data = q.top();   q.pop();
            ll total = -data.first;
            int x = data.second;

            if (x == n-1){
                break;
            }

            if (visited[x] < total){
                continue;
            }

            for (const auto& [nx, c] : edges[x]){
                if (c < m){
                    continue;
                }
                ll newTotal = total + c;
                if (newTotal > k){
                    continue;
                }
                if (visited[nx] > newTotal){
                    visited[nx] = newTotal;
                    q.emplace(-newTotal, nx);
                }
            }
        }

        if (visited[n-1] < LONG_LONG_MAX){
            return true;
        }
        else {
            return false;
        }
    }
public:
    int findMaxPathScore(vector<vector<int>>& es, vector<bool>& online, ll k) {
        n = online.size();
        edges.assign(n, vector<pair<int, int>>(0));
        this->k = k;

        for (vector<int>& e : es){
            int u = e[0], v = e[1], cost = e[2];
            if (online[u] && online[v])
                edges[u].emplace_back(v, cost);
        }

        int l = -1, r = 1'000'000'001;

        while (r-l > 1){
            int mid = (l + r)/2;
            if (cal(mid)){
                l = mid;
            }
            else {
                r = mid;
            }
        }

        return l;
    }
};