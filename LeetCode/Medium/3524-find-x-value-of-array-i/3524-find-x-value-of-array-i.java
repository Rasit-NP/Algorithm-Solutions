class Solution {
    public long[] resultArray(int[] nums, int k) {

        int n = nums.length;

        for (int i=0; i<n; ++i){
            nums[i] %= k;
        }

        long[] res = new long[k];
        long[] nowCount = new long[k];

        for (int num : nums){
            long[] newCount = new long[k];

            for (int i=0; i<k; ++i){
                int idx = (num * i) % k;
                newCount[idx] += nowCount[i];
            }

            ++newCount[num];

            for (int i=0; i<k; ++i){
                nowCount[i] = newCount[i];
                res[i] += nowCount[i];
            }
        }

        return res;
    }
}