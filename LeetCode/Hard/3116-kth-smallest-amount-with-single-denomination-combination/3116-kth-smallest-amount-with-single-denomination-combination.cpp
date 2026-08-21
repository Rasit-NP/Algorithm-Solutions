# include <vector>
# include <numeric>
using namespace std;
typedef long long llong;

class Solution {
private:
    int n;
    static vector<int> memo;

    llong getLcm(int x){
        if (memo[x] != -1)
            return memo[x];
        
        llong res = 1;
        for (llong i=1; i<=25; i++){
            if (x & (1<<i)){
                res = lcm(res, i);
            }
        }

        memo[x] = res;
        return res;
    }

    llong get(vector<int>& coins, llong x){
        llong res = 0;
        for (int mask = 1; mask < (1 << n); mask++){
            llong l = 1;
            for (int i = 0; i < n; i++){
                if (mask & (1 << i)){
                    l = lcm(l, (llong)coins[i]);
                    if (l > x) break;
                }
            }
            int bits = __builtin_popcount(mask);
            if (bits & 1)
                res += x / l;
            else
                res -= x / l;
        }
        return res;
    }
public:
    llong findKthSmallest(vector<int>& coins, int k) {
        n = coins.size();
        llong l = 0, r = 50'000'000'000;

        while (r-l > 1){
            llong mid = (l+r)/2;

            if (get(coins, mid) < k){
                l = mid;
            }
            else {
                r = mid;
            }
        }

        return r;
    }
};

vector<int> Solution::memo(1<<26, -1);