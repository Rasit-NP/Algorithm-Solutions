class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sz = nums.size();
        bool isFin = false;
        vector<int> ans(2);
        for (int i=0; i<sz; i++){
            for (int j=i+1; j<sz; j++){
                if (nums[i] + nums[j] == target){
                    ans[0] = i, ans[1] = j;
                    isFin = true;
                    break;
                }
            }
            if (isFin)
                break;
        }
        return ans;
    }
};