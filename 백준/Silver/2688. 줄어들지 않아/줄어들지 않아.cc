# include <iostream>
# include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    int t;  cin >> t;
    vector<vector<long long>> dp(65, vector<long long>(10, 0));
    vector<long long> ans(65, 0);
    for (int i=0; i<10; i++){
        dp[1][i] = 1;
        ans[1]++;
    }
    for (int len=2; len<65; len++){
        for (int i=0; i<10; i++){
            for (int j=i; j>=0; j--){
                dp[len][i] += dp[len-1][j];
            }
            ans[len] += dp[len][i];
        }
    }
    while (t--){
        int n;  cin >> n;
        cout << ans[n] << '\n';
    }
}