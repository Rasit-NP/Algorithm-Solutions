# include <vector>
# include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        int maxi = 0;
        string ans;
        
        for (int i=0; i<n; i++){
            dp[i][i] = 1;
        }
        maxi = 1;
        ans = s.substr(0, 1);
        for (int i=0; i<n-1; i++){
            if (s[i] == s[i+1]){
                dp[i][i+1] = 2;
                maxi = 2;
                ans = s.substr(i, 2);
            }
        }

        for (int len = 3; len<=n; len++){
            for (int i=0; i<=n-len; i++){
                if (dp[i+1][i+len-2] && s[i] == s[i+len-1]){
                    int val = dp[i+1][i+len-2] + 2;
                    dp[i][i+len-1] = val;
                    if (maxi < val){
                        maxi = val;
                        ans = s.substr(i, len);
                    }
                }
            }
        }

        return ans;
    }
};