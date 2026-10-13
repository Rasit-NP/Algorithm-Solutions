class Solution {
    public long maxAlternatingSum(int[] nums) {
        int n = nums.length;

        int[] squared = new int[n];

        for (int i=0; i<n; ++i){
            squared[i] = nums[i] * nums[i];
        }

        Arrays.sort(squared);

        int head = 0, tail = n-1;
        long res = 0;
        while (tail >= head){
            if (tail != head)
                res -= squared[head++];
            res += squared[tail--];
        }

        return res;
    }
}