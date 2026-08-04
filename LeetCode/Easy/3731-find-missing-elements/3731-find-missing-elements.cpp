# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> res;

        for (int i=nums.front(), maxi = nums.back(), idx = 0; i<=maxi; i++){
            if (i != nums[idx]){
                res.emplace_back(i);
            }
            else {
                ++idx;
            }
        }

        return res;
    }
};