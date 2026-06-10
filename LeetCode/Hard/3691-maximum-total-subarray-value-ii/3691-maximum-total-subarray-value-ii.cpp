#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
using llong = long long;

class Solution {
    int n;
    const vector<int>* a;

    pair<llong, llong> solve(llong X) {
        const vector<int>& nums = *a;
        deque<pair<llong, llong>> dmax, dmin;
        llong curMax = 0, curMin = 0;
        int lo = 0;
        llong cnt = 0, sum = 0;
        for (int r = 0; r < n; r++) {
            llong v = nums[r], c = 1;
            while (!dmax.empty() && dmax.back().first <= v) {
                auto pr = dmax.back(); dmax.pop_back();
                curMax -= pr.first * pr.second; c += pr.second;
            }
            dmax.push_back({v, c}); curMax += v * c;
            c = 1;
            while (!dmin.empty() && dmin.back().first >= v) {
                auto pr = dmin.back(); dmin.pop_back();
                curMin -= pr.first * pr.second; c += pr.second;
            }
            dmin.push_back({v, c}); curMin += v * c;
            while (dmax.front().first - dmin.front().first > X) {
                curMax -= dmax.front().first; if (--dmax.front().second == 0) dmax.pop_front();
                curMin -= dmin.front().first; if (--dmin.front().second == 0) dmin.pop_front();
                lo++;
            }
            cnt += (llong)(r - lo + 1);
            sum += curMax - curMin;
        }
        return {cnt, sum};
    }

public:
    long long maxTotalValue(vector<int>& nums, int k) {
        n = nums.size();
        a = &nums;
        llong total = (llong)n * (n + 1) / 2;
        const llong INF = 4000000000000000000LL;
        llong allSum = solve(INF).second;

        int mxv = *max_element(nums.begin(), nums.end());
        int mnv = *min_element(nums.begin(), nums.end());

        auto cntGe = [&](llong v) -> llong {
            if (v <= 0) return total;
            return total - solve(v - 1).first;
        };

        llong loT = 0, hiT = (llong)mxv - mnv, T = 0;
        while (loT <= hiT) {
            llong mid = loT + (hiT - loT) / 2;
            if (cntGe(mid) >= k) { T = mid; loT = mid + 1; }
            else hiT = mid - 1;
        }
        llong cntGeT1 = cntGe(T + 1);
        llong sumGeT1 = allSum - solve(T).second;
        return sumGeT1 + ((llong)k - cntGeT1) * T;
    }
};