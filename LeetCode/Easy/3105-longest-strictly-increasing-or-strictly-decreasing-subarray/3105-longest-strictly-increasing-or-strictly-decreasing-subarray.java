class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int res = 0;
        int increasing = 0;
        int decreasing = 0;
        int bef = nums[0];
        for (int num : nums){
            if (bef > num){
                ++increasing;
                decreasing = 1;
            }
            else if (bef < num){
                ++decreasing;
                increasing = 1;
            }
            else {
                increasing = 1;
                decreasing = 1;
            }
            bef = num;
            res = Math.max(res, Math.max(increasing, decreasing));
        }

        return res;
    }
}