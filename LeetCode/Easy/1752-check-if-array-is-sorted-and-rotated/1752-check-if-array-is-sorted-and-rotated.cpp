# include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        bool chk = false;
        for (int i=1; i<n; i++){
            if (nums[i] >= nums[i-1]){
                continue;
            }
            else if (chk){
                return false;
            }
            else {
                chk = true;
            }
        }

        if (chk && nums[0] < nums[n-1]){
            return false;
        }
        else {
            return true;
        }
    }
};