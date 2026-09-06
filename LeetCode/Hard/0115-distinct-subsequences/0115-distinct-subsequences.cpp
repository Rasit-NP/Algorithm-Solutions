# include <string>
# include <vector>
# include <climits>
using namespace std;
typedef long long llong;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        vector<vector<llong>> dp(n2, vector<llong>(n1));

        dp[0][0] = (t[0] == s[0]);

        for (int j=1; j<n1; ++j){
            dp[0][j] = dp[0][j-1] + (t[0] == s[j]);
        }

        for (int i=1; i<n2; ++i){
            for (int j=1; j<n1; ++j){
                dp[i][j] = dp[i][j-1] + (t[i] == s[j] ? dp[i-1][j-1] : 0);
                dp[i][j] %= INT_MAX;
            }
        }

        return dp.back().back();
    }
};