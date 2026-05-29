# include <algorithm>
# include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i=0; i<n; i++){
            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int start = nums[i];
            int l = i+1, r = n-1;
            while (l < r){
                int now = nums[l] + nums[r];
                if (now + start < 0){
                    ++l;
                }
                else if (now + start > 0){
                    --r;
                }
                else {
                    res.push_back({start, nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l+1]){
                        ++l;
                    }
                    while (l < r && nums[r] == nums[r-1]){
                        --r;
                    }
                    ++l;
                    --r;
                }
            }
        }

        return res;
    }
};