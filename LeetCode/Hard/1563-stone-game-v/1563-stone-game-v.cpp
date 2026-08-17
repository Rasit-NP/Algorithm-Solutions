# include <vector>
# include <algorithm>
using namespace std;

class Solution {
private:
    int n;
    vector<vector<int>> dp;
    vector<int> prefixSum;

    int getSum(int a, int b){
        return prefixSum[b+1] - prefixSum[a];
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.assign(n, vector<int>(n, -1));
        prefixSum.assign(n+1, 0);

        for (int i=0; i<n; i++){
            dp[i][i] = 0;
            prefixSum[i+1] = prefixSum[i] + stoneValue[i];
        }

        for (int d=1; d<n; d++){
            for (int s=0, e=s+d; e<n; s++, e++){
                int score = 0;
                for (int mid=s; mid<e; mid++){
                    int l = getSum(s, mid);
                    int r = getSum(mid+1, e);

                    if (l < r){
                        score = max(score, dp[s][mid] + l);
                    }
                    else if (l > r){
                        score = max(score, dp[mid+1][e] + r);
                    }
                    else {
                        score = max({score, dp[s][mid] + l, dp[mid+1][e] + r});
                    }
                }
                dp[s][e] = score;
            }
        }
        return dp[0][n-1];
    }
};