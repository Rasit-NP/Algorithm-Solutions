class Solution {
    public int minMoves(int[] nums) {
        int min = 1<<30;

        for (int num : nums){
            min = Math.min(num, min);
        }

        int res = 0;

        for (int num : nums){
            res += num - min;
        }

        return res;
    }
}