# include <vector>
# include <algorithm>
# define N 100'000
using namespace std;

namespace {
int sq(int x){
    return x*x;
}
};

class Solution {
private:
    int f(int x){
        if (dp[x] == -1){
            dp[0] = 0;
            for (int x=1; x<=N; x++){
                for (int dx=1; x-sq(dx)>=0; dx++){
                    dp[x] = max(dp[x], dp[x-sq(dx)]^1);
                    if (dp[x])
                        break;
                }
            }
        }

        return dp[x];
    }
public:
    static vector<int> dp;
    bool winnerSquareGame(int n) {
        return f(n);
    }
};

vector<int> Solution::dp(N+1, -1);