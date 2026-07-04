class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        int[] cnt = new int[101];
        for (int num : nums){
            cnt[num]++;
        }
        for (int i=1; i<=100; i++){
            cnt[i] += cnt[i-1];
        }

        for (int i=0; i<n; i++){
            int val = nums[i];
            if (val != 0){
                res[i] = cnt[nums[i]-1];
            }
            else {
                res[i] = 0;
            }
        }

        return res;
    }
}