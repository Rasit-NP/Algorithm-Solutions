# include <iostream>
# include <vector>
# include <climits>
# include <algorithm>
using namespace std;

struct Edge{
    int nx, cost;

    Edge(){
        this -> nx = 0;
        this -> cost = 0;
    }

    Edge(int x, int c){
        this->nx = x;
        this->cost = c;
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    vector<vector<Edge>> edges(n, vector<Edge>(0));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            int cost;   cin >> cost;
            if (i != j){
                edges[i].push_back(Edge(j, cost));
            }
        }
    }

    vector<vector<int>> dp(n+1, vector<int>(1<<n, INT_MAX));

    int state = 0;
    int cnt = 0;
    for (int i=0; i<n; i++){
        char v; cin >> v;
        if (v == 'Y'){
            state += 1<<i;
            cnt++;
        }
    }
    dp[cnt][state] = 0;

    int p;  cin >> p;

    if (cnt >= p){
        cout << 0;
        return 0;
    }

    for (int count = cnt; count<=p; count++){
        for (int state = 0; state < (1<<n); state++){
            if (dp[count][state] == INT_MAX)
                continue;
            for (int x = 0; x<n; x++){
                if (state & (1<<x)){
                    for (const Edge& edge : edges[x]){
                        int nx = edge.nx;
                        if (state & (1 << nx))
                            continue;
                        int next_state = state + (1<<nx);
                        dp[count+1][next_state] = min(dp[count+1][next_state], dp[count][state] + edge.cost);
                    }
                }
            }
        }
    }

    int ans = INT_MAX;
    for (int state = 0; state < (1<<n); state++){
        ans = min(ans, dp[p][state]);
    }
    if (ans == INT_MAX)
        cout << -1;
    else
        cout << ans;
}