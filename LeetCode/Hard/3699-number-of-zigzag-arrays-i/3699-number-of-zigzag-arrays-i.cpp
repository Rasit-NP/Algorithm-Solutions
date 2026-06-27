# include <vector>
using namespace std;

class Solution {
private:
    int sz;
    int MAX = 1'000'000'007;
    vector<vector<int>> dp;

    void sumAndMod(int& a, int b){
        a += b;
        if (a >= MAX)
            a -= MAX;
    }
public:
    int zigZagArrays(int n, int l, int r) {
        sz = r-l+1;
        dp.assign(n+1, vector<int>(sz*2, 0));

        for (int num=0; num<=r-l; ++num){
            dp[1][num] = 1;
            dp[1][num+sz] = 1;
        }

        for (int i=2; i<=n; ++i){
            int val = 0;
            for (int num=0; num<r-l; ++num){
                sumAndMod(val, dp[i-1][num]);
                sumAndMod(dp[i][num+sz+1], val);
            }
            val = 0;
            for (int num=r-l; num>0; --num){
                sumAndMod(val, dp[i-1][num+sz]);
                sumAndMod(dp[i][num-1], val);
            }
        }

        int res = 0;
        for (int num=0; num<=r-l; ++num){
            sumAndMod(res, dp[n][num+sz]);
            sumAndMod(res, dp[n][num]);
        }

        return res;
    }
};