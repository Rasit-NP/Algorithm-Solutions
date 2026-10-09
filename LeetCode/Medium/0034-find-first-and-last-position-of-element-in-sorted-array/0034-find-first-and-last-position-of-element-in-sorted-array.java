class Solution {
    public int[] searchRange(int[] nums, int target) {
        int n = nums.length;
        if (n == 0){
            return new int[]{-1, -1};
        }
        int[] res = new int[2];

        int l = 0, r = n;
        while (r-l > 1){
            int mid = (l + r)/2;
            if (nums[mid] > target){
                r = mid;
            }
            else {
                l = mid;
            }
        }
        res[1] = (nums[l] == target ? l : -1);

        l = -1;
        r = n-1;
        while (r-l > 1){
            int mid = (l + r)/2;
            if (nums[mid] < target){
                l = mid;
            }
            else {
                r = mid;
            }
        }
        res[0] = (nums[r] == target ? r : -1);

        return res;
    }
}