class Solution {
    public int maximumStrongPairXor(int[] nums) {
        int n = nums.length;
        int res = 0;

        for (int i=0; i<n; ++i){
            int x = nums[i];
            for (int j=i; j<n; ++j){
                int y = nums[j];
                if (Math.abs(x - y) <= Math.min(x, y))
                    res = Math.max(res, x ^ y);
            }
        }

        return res;
    }
}