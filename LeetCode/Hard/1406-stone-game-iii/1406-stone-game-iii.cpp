# include <vector>
# include <string>
# include <climits>
# include <algorithm>
using namespace std;

class Solution {
private:
    int n;
    vector<int> dp, nums;

    int foo(int x){
        if (x >= n)
            return 0;
        else if (dp[x] != -1)
            return dp[x];

        int val = INT_MIN;
        int now = 0;
        for (int i=1; i<=3; i++){
            if (x+i > n)
                break;
            now += nums[x+i-1];
            val = max(val, now - foo(x+i));
        }

        dp[x] = val;
        return val;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        nums = move(stoneValue);
        dp.assign(n, -1);
        dp[n-1] = nums[n-1];

        int val = foo(0);

        if (val > 0)
            return "Alice";
        else if (val == 0)
            return "Tie";
        else
            return "Bob";
    }
};