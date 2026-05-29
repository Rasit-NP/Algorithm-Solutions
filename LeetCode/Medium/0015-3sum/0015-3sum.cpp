# include <algorithm>
# include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> sets;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i=0; i<n; i++){
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
                    if (sets.find({start, nums[l], nums[r]}) == sets.end()){
                        res.push_back({start, nums[l], nums[r]});
                        sets.insert({start, nums[l], nums[r]});
                    }
                    ++l;
                }
            }
        }

        return res;
    }
};