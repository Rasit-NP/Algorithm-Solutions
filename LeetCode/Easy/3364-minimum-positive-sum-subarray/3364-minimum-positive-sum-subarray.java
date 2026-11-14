class Solution {
    public int minimumSumSubarray(List<Integer> nums, int l, int r) {
        int n = nums.size();
        int res = Integer.MAX_VALUE;

        for (int i = 0; i < n; ++i) {
            int now = 0;
            int len = 0;

            for (; len < l - 1 && i + len < n; ++len) {
                now += nums.get(i + len);
            }

            for (; len < r && i + len < n; ++len) {
                now += nums.get(i + len);
                if (now > 0) res = Math.min(res, now);
            }
        }

        return res == Integer.MAX_VALUE ? -1 : res;
    }
}