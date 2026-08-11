# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int total = nums[0];
        int i;

        for (i=1; i<n; i++){
            if (nums[i] == nums[i-1] + 1){
                total += nums[i];
            }
            else {
                break;
            }
        }
        
        sort(nums.begin(), nums.end());

        for (int num : nums){
            if (num < total)
                continue;
            else if (num == total){
                total += 1;
                continue;
            }
        }

        return total;
    }
};