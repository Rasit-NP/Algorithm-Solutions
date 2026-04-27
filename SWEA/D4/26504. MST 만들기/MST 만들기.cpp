# include <iostream>
# include <vector>
# include <algorithm>
typedef long long llong;
using namespace std;

void solve(){
    int n;  cin >> n;
    vector<int> costs(n*(n-1)/2, 0);
    for (int i=0; 2*i < n*(n-1); i++){
        cin >> costs[i];
    }

    sort(costs.begin(), costs.end());

    llong minSum = 0;
    for (int i=0; i<n-1; i++){
        minSum += costs[i];
    }

    llong maxSum = 0;
    vector<vector<bool>> duplicated(n, vector<bool>(n, false));
    for (int i=0; i<n; i++){
        duplicated[i][i] = true;
    }

    int nowIdx = 0;

    for (int cost : costs){
        int newIdx = nowIdx+1;
        bool allocated = false;
        for (int i=0; i<newIdx; i++){
            for (int j=0; j<newIdx; j++){
                if (!duplicated[i][j]){
                    duplicated[i][j] = true;
                    duplicated[j][i] = true;
                    allocated = true;
                }
                if (allocated){
                    break;
                }
            }
            if (allocated){
                break;
            }
        }
        if (!allocated){
            duplicated[0][newIdx] = true;
            duplicated[newIdx][0] = true;
            maxSum += cost;
            ++nowIdx;
        }
    }

    cout << minSum << ' ' << maxSum << '\n';
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;
    while (t--){
        solve();
    }
}