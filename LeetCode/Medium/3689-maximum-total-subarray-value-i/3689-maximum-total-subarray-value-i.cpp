# include <algorithm>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mini = 1'000'000'001;
        int maxi = -1;

        for (int num : nums){
            mini = min(mini, num);
            maxi = max(maxi, num);
        }

        return (long long)(maxi-mini) * k;
    }
};