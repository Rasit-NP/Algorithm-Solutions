# include <vector>
# include <string>
# include <climits>
# include <algorithm>
using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, INT_MIN);
        dp[n] = 0;
        
        for (int x=n-1; x>=0; x--){
            int now = 0;
            for (int i=0; i<3; i++){
                if (x+i>=n)
                    break;
                now += nums[x+i];
                dp[x] = max(dp[x], now - dp[x+i+1]);
            }
        }

        if (dp[0] > 0)
            return "Alice";
        else if (dp[0] == 0)
            return "Tie";
        else
            return "Bob";
    }
};