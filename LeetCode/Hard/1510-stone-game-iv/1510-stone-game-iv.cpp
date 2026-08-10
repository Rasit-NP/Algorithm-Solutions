# include <vector>
# include <algorithm>
using namespace std;

namespace {
int sq(int x){
    return x*x;
}
};

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 0;

        for (int x=1; x<=n; x++){
            for (int dx=1; x-sq(dx)>=0; dx++){
                dp[x] = max(dp[x], dp[x-sq(dx)]^1);
            }
        }

        return dp[n];
    }
};