# include <vector>
# include <climits>
# include <algorithm>
using namespace std;

class Solution {
private:
    int n;
    vector<int> presum;
    vector<vector<int>> dp;

    int getSum(int i, int j){
        return presum[j+1] - presum[i];
    }

    int play(int m, int x){
        if (x >= n)
            return 0;
        else if (dp[m][x] != INT_MIN)
            return dp[m][x];

        int val = INT_MIN;
        for (int i=0, lim=2*m; i<lim; i++){
            if (x+i >= n)
                break;
            val = max(val, getSum(x, x+i) - play(min(max(m, i+1), n), x+i+1));
        }

        dp[m][x] = val;
        return val;
    }
public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        dp.assign(n+1, vector<int>(n, INT_MIN));

        for (int i=1, val=piles.back(); i<=n; i++){
            dp[i][n-1] = val;
        }

        presum.reserve(n+1);
        presum.emplace_back(0);
        for (int pile : piles){
            presum.emplace_back(presum.back() + pile);
        }

        int val = play(1, 0);
        
        return (presum.back() + val)/2;
    }
};