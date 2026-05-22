# include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int mini, minIdx;
        int l = -1, r = n-1;
        while (r-l > 1){
            int mid = (l+r)/2;
            if (nums[mid] > nums.back()){
                l = mid;
            }
            else {
                r = mid;
            }
        }
        mini = nums[r], minIdx = r;

        if (target == mini){
            return minIdx;
        }
        else if (target > nums.back()){
            l = -1, r = minIdx-1;
        }
        else {
            l = minIdx-1, r = n-1;
        }

        while (r-l > 1){
            int mid = (l+r)/2;
            if (nums[mid] > target){
                r = mid;
            }
            else if (nums[mid] < target) {
                l = mid;
            }
            else {
                return mid;
            }
        }

        if (r < 0){
            return -1;
        }
        if (nums[r] == target){
            return r;
        }
        else {
            return -1;
        }
    }
};