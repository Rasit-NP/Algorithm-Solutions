# include <algorithm>
# include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int res = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());

        for (int i=0; i<n; i++){
            int x = nums[i];

            int l = 0, r = n-1;
            int sum;
            while (l < r){
                if (i == l){
                    ++l;
                    continue;
                }
                if (i == r){
                    --r;
                    continue;
                }
                sum = x + nums[l] + nums[r];
                if (abs(target - sum) < abs(target - res)){
                    res = sum;
                }
                if (sum < target){
                    ++l;
                }
                else if (sum > target){
                    --r;
                }
                else {
                    return target;
                }
            }
        }

        return res;
    }
};