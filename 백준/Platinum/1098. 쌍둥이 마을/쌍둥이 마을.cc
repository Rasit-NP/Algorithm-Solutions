# include <iostream>
# include <vector>
# include <climits>
# include <algorithm>
using namespace std;

vector<vector<int>> edges;
vector<int> dp;
int n, p, d;

int getTwin(int state, int x){
    int shifted = state >> (2*x);
    return (shifted & 1) + (shifted & 2);
}

int getTwins(int state){
    int res = 0;
    while (state){
        res += (state&1) + (state&2);
        state >>= 2;
    }
    return res/2;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n;
    vector<pair<int, int>> towns(n, {0, 0});
    dp.assign(1<<(2*n), INT_MAX);   dp[0] = 0;
    for (int i=0; i<n; i++){
        cin >> towns[i].first >> towns[i].second;
    }

    cin >> p >> d;

    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            int dist = abs(towns[i].first-towns[j].first) + abs(towns[i].second-towns[j].second);
            if (dist >= d){
                edges.push_back({dist, i, j});
            }
        }
    }

    sort(edges.begin(), edges.end());
    
    for (int i = edges.size() - 1; i >= 0; i--){
        int dist = edges[i][0], x = edges[i][1], nx = edges[i][2];
        for (int state = (1<<(2*n))-1; state >= 0; state--){
            int newState = state + (1 << (2*x)) + (1 << (2*nx));
            if (newState < (1<<(2*n)) && dp[state] < INT_MAX && getTwin(state, x) < p && getTwin(state, nx) < p){
                dp[newState] = min(dp[newState], dp[state] + dist);
            }
        }
    }

    int cntTwins = 0;
    int sumDists = INT_MAX;
    for (int state=0; state < (1<<(2*n)); state++){
        if (dp[state] == INT_MAX){
            continue;
        }
        int twins = getTwins(state);
        if (twins>cntTwins){
            cntTwins = twins;
            sumDists = dp[state];
        }
        else if (twins == cntTwins){
            sumDists = min(sumDists, dp[state]);
        }
    }
    cout << cntTwins << ' ' << sumDists;
}
