class Solution {

    public int minOperations(int[] nums, int x) {
        int n = nums.length;
        int sums = 0;
        for (int num : nums){
            sums += num;
        }

        int target = sums - x;
        System.out.println(target);

        int l = 0, r = 0;
        int now = 0;
        int sz = -1;

        while (r <= n){
            if (l == r){
                if (now == target){
                    sz = Math.max(sz, r - l);
                }
                if (r == n)
                    break;
                now += nums[r++];
            }
            else if (now < target){
                if (r == n)
                    break;
                now += nums[r++];
            }
            else if (now > target){
                now -= nums[l++];
            }
            else if (now == target){
                sz = Math.max(sz, r - l);
                now -= nums[l++];
            }
        }

        return sz != -1 ? n - sz : -1;
    }
}