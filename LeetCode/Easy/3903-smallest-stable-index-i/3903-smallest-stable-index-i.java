class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int n = nums.length;
        int[] maxi = new int[n];
        int[] mini = new int[n];
        
        int locM = -1, locm = 1_000_000_001;

        for (int i=0; i<n; i++){
            locM = Math.max(locM, nums[i]);
            locm = Math.min(locm, nums[n-i-1]);
            maxi[i] = locM;
            mini[n-i-1] = locm;
        }

        for (int i=0; i<n; i++){
            if (maxi[i] - mini[i] <= k)
                return i;
        }

        return -1;
    }
}