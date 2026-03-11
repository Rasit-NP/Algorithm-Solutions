# include <iostream>
# include <vector>
# define MAX 998244353
using namespace std;

vector<vector<int>> dp(5003, vector<int>(5003, 0));

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    dp[2][1] = 1;
    for (int len = 2; len<5001; len++){
        for (int size = 0; size<5001; size++){
            if (dp[len][size]){
                if (size){
                    dp[len+1][size-1] += dp[len][size];
                    dp[len+1][size-1] %= MAX;
                }
                dp[len+2][size+1] += dp[len][size];
                dp[len+2][size+1] %= MAX;
            }
        }
    }

    int t;  cin >> t;
    while (t--){
        int n;  cin >> n;
        int ans = 0;
        for (const int& num : dp[n]){
            ans += num;
            ans %= MAX;
        }
        if (ans)
            cout << ans << '\n';
        else
            cout << "-1\n";
    }
}