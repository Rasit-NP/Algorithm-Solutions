# include <algorithm>

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int nowSum = 0;
        int localSum = 0;
        int len = nums.size();
        int ans = 0;

        for (int i=0; i<len; i++){
            nowSum += i*nums[i];
            localSum += nums[i];
        }
        ans = nowSum;
        for (int i=len-1; i>=0; i--){
            nowSum -= len*nums[i];
            nowSum += localSum;
            ans = max(ans, nowSum);
        }

        return ans;
    }
};