class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int n = nums.length;
        int[] maxi = new int[n];
        int[] mini = new int[n];

        maxi[0] = nums[0];
        mini[n-1] = nums[n-1];

        for (int i=1; i<n; i++){
            maxi[i] = Math.max(maxi[i-1], nums[i]);
            mini[n-i-1] = Math.min(mini[n-i], nums[n-i-1]);
        }

        for (int i=0; i<n; i++){
            if (maxi[i] - mini[i] <= k)
                return i;
        }

        return -1;
    }
}