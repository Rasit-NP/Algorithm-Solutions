# include <vector>
# include <unordered_map>
# include <algorithm>
# include <cmath>
using namespace std;

class Solution {
private:
    int res = 0;
    int sq = sqrt(2'000'000'000);
    unordered_map<int, int> count;
    unordered_map<int, int> dp;

    int calDp(int num){
        if (count.find(num) == count.end()){
            return 0;
        }
        if (dp[num]){
            return dp[num];
        }

        if (num >= sq){
            dp[num] = 1;
        }
        else if (num == 1){
            dp[1] = count[1] - !(count[1]&1);
        }
        else {
            if (count[num] >= 2 && calDp(num*num)){
                dp[num] = dp[num*num] + 2;
            }
            else {
                dp[num] = 1;
            }
        }
        return dp[num];
    }
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        for (int num : nums){
            count[num]++;
        }

        for (const auto& [num, val] : count){
            res = max(res, calDp(num));
        }

        return res;
    }
};