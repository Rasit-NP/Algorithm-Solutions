class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int res = 0, now = 0;
        int n = nums.length;

        for (int i=0; i<n; i++){
            if (nums[i] == 1){
                ++now;
            }
            else {
                res = Math.max(res, now);
                now = 0;
            }
        }

        res = Math.max(res, now);

        return res;
    }
}