# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> dp(n, 0);
        vector<int> sums(n, 0);

        sums[0] = stones[0];
        for (int i=1; i<n; i++){
            sums[i] = sums[i-1] + stones[i];
        }

        dp[n-1] = sums[n-1];
        int maxi = dp[n-1];
        for (int i=n-2; i>=0; i--){
            dp[i] = sums[i] - maxi;
            maxi = max(maxi, dp[i]);
        }

        return *max_element(dp.begin()+1, dp.end());
    }
};