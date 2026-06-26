# include <vector>
using namespace std;
typedef long long llong;

class Solution {
public:
    llong countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size(), pre = n+1;
        llong res = 0;
        vector<int> cnt(2*n+2), acc(2*n+2);
        cnt[pre] = 1, acc[pre] = 1;

        for (int num : nums){
            pre += (num == target ? 1 : -1);
            cnt[pre]++;
            acc[pre] = acc[pre-1] + cnt[pre];
            res += acc[pre-1];
        }

        return res;
    }
};