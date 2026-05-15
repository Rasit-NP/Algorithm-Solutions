class Solution {
private:
    int n;
public:
    int findMin(vector<int>& nums) {
        n = nums.size();
        int r = n-1, l = -1;
        while (r-l > 1){
            int mid = (l+r)/2;
            if (nums[mid] <= nums.back()){
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return nums[r];
    }
};