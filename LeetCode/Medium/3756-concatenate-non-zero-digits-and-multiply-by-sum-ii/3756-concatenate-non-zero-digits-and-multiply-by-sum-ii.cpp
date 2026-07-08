# include <vector>
# include <string>
# define MAX 1'000'000'007
using namespace std;
typedef long long ll;

class Solution {
private:
    int len;
    vector<int> sums;
    vector<int> cnt;
    vector<ll> xs;

    int solve(int l, int r){
        int res;
        int diff = cnt[r+1] - cnt[l];
        int sum = sums[r+1] - sums[l];
        ll mult = 1, base = 10, x;
        while (diff){
            if (diff & 1){
                mult *= base;
                mult %= MAX;
            }
            base *= base;
            base %= MAX;
            diff >>= 1;
        }

        int a = xs[r+1];
        int b = (xs[l] * mult) % MAX;
        if (a > b){
            x = a - b;
        }
        else {
            x = MAX + a - b;
        }

        res = (x*sum) % MAX;

        return res;
    }
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        len = s.size();
        sums.assign(len+1, 0);
        xs.assign(len+1, 0);
        cnt.assign(len+1, 0);
        vector<int> res;
        res.reserve(queries.size());

        for (int i=1; i<=len; ++i){
            if (s[i-1] == '0'){
                xs[i] = xs[i-1];
                cnt[i] = cnt[i-1];
            }
            else {
                xs[i] = xs[i-1] * 10 + (s[i-1] - '0');
                xs[i] %= MAX;
                cnt[i] = cnt[i-1] + 1;
            }
            sums[i] = sums[i-1] + (s[i-1] - '0');
        }

        for (vector<int>& q : queries){
            int l = q[0], r = q[1];

            res.emplace_back(solve(l, r));
        }

        return res;
    }
};