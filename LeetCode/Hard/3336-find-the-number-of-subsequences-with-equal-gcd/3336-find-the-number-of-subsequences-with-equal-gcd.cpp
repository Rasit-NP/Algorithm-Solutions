# include <vector>
# include <algorithm>
using namespace std;

class Solution {
private:
    int n, len=0;
    int MOD = 1'000'000'007;
    vector<vector<int>> dp;
    vector<vector<int>> memo;
    int getGCD(int a, int b);

public:
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        for (int num : nums){
            len = max(len, num);
        }

        dp.assign(len+1, vector<int>(len+1, 0));
        memo.assign(len+1, vector<int>(len+1, 0));
        dp[0][0] = 1;
        for (int num : nums){
            vector<vector<int>> ndp = dp;
            for (int i=0; i<=len; ++i){
                int gcd1 = getGCD(i, num);
                for (int j=0; j<=len; ++j){
                    int gcd2 = getGCD(j, num);
                    if (!dp[i][j])
                        continue;
                    ndp[gcd1][j] += dp[i][j];
                    if (ndp[gcd1][j] >= MOD){
                        ndp[gcd1][j] -= MOD;
                    }
                    ndp[i][gcd2] += dp[i][j];
                    if (ndp[i][gcd2] >= MOD){
                        ndp[i][gcd2] -= MOD;
                    }
                }
            }
            dp = move(ndp);
        }

        int res = 0;
        for (int i=1; i<=len; ++i){
            res += dp[i][i];
            if (res >= MOD){
                res -= MOD;
            }
        }

        return res;
    }
};

int Solution::getGCD(int a, int b){
    if (memo[a][b]){
        return memo[a][b];
    }
    int A = a, B = b;
    if (a < b)
        swap(a, b);
    if (b == 0){
        return a;
    }
    while (a % b){
        int tmp = a % b;
        a = b;
        b = tmp;
    }

    memo[A][B] = b;
    memo[B][A] = b;
    return b;
}