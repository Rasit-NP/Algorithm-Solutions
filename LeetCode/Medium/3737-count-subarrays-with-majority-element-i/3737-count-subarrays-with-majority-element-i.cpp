# include <vector>
using namespace std;

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int res = 0;
        for (int start=0; start<n; ++start){
            int cntTarget = 0;
            int len = 1;
            for (int end=start; end<n; ++end, ++len){
                if (nums[end] == target){
                    ++cntTarget;
                }
                if (cntTarget > (len/2)){
                    ++res;
                }
            }
        }

        return res;
    }
};