# include <iostream>
# include <vector>
# include <climits>
# include <algorithm>
using namespace std;

int n, m;
vector<int> male, female;
vector<vector<int>> dp;
vector<vector<int>> mini;

void sortVec(vector<int>& vec){
    sort(vec.begin(), vec.end());
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n >> m;
    male.assign(n, 0), female.assign(m, 0);
    
    for (int i=0; i<n; ++i){
        cin >> male[i];
    }
    for (int i=0; i<m; ++i){
        cin >> female[i];
    }
    
    if (n > m){
        swap(n, m);
        swap(male, female);
    }
    
    dp.assign(n, vector<int>(m));
    mini.assign(n, vector<int>(m));
    sortVec(male);
    sortVec(female);

    dp[0][0] = abs(male[0] - female[0]);
    mini[0][0] = dp[0][0];

    for (int j=1; j<m; j++){
        dp[0][j] = abs(male[0] - female[j]);
        mini[0][j] = min(mini[0][j-1], dp[0][j]);
    }
    for (int i=1; i<n; i++){
        dp[i][i] = dp[i-1][i-1] + abs(male[i] - female[i]);
        mini[i][i] = dp[i][i];
    }

    for (int i=1; i<n; i++){
        for (int j=i+1; j<m; j++){
            dp[i][j] = mini[i-1][j-1] + abs(male[i] - female[j]);
            mini[i][j] = min(mini[i][j-1], dp[i][j]);
        }
    }

    int ans = INT_MAX;
    for (int j=n-1; j<m; j++){
        ans = min(ans, dp[n-1][j]);
    }

    cout << ans;
}