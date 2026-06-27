# include <vector>
# include <unordered_map>
# include <algorithm>
# include <cmath>
using namespace std;

class Solution {
private:
    int sq = sqrt(2'000'000'000);
    unordered_map<int, int> count;
    unordered_map<int, int> dp;
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int res = upper_bound(nums.begin(), nums.end(), 1) - lower_bound(nums.begin(), nums.end(), 1);
        res = res - !(res&1);
        
        for (int i=n-1; i>=0; --i){
            int num = nums[i];
            count[num]++;
            if (num > sq){
                dp[num] = 1;
            }
            else if (num == 1){
                dp[num] = 1;
            }
            else {
                if (count[num] >= 2 && dp[num*num]){
                    dp[num] = dp[num*num] + 2;
                }
                else {
                    dp[num] = 1;
                }
            }
            res = max(res, dp[num]);
        }

        return res;
    }
};