# include <vector>
using namespace std;

class Solution {
private:
    int n;
    vector<vector<int>> dp;
public:
    bool stoneGame(vector<int>& piles) {
        n = piles.size();
        dp.assign(n, vector<int>(n, -1));

        for (int i=0; i<n; i++){
            dp[i][i] = -piles[i];
        }

        for (int len=1; len<n; len++){
            for (int l=0; l<n-len; l++){
                if (len&1){
                    dp[l][l+len] = max(dp[l+1][l+len] + piles[l], dp[l][l+len-1] + piles[l+len]);
                }
                else {
                    dp[l][l+len] = min(dp[l+1][l+len] - piles[l], dp[l][l+len-1] - piles[l+len]);
                }
            }
        }

        return dp[0][n-1] > 0;
    }
};