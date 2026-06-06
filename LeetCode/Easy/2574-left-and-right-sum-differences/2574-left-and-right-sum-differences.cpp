# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);

        vector<int> leftSum(n, 0);
        vector<int> rightSum(n, 0);

        for (int i=0; i<n; i++){
            if (i){
                leftSum[i] = leftSum[i-1] + nums[i-1];
                rightSum[n-i-1] = rightSum[n-i] + nums[n-i];
            }
            else{
                leftSum[0] = 0;
                rightSum[n-1] = 0;
            }
        }

        for (int i=0; i<n; i++){
            res[i] = abs(leftSum[i] - rightSum[i]);
        }

        return res;
    }
};