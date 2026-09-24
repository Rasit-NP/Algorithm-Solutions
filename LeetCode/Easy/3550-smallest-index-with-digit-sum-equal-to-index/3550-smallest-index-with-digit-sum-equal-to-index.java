class Solution {

    private int getDigitSum(int num){
        int res = 0;
        while (num > 0){
            res += num % 10;
            num /= 10;
        }

        return res;
    }
    public int smallestIndex(int[] nums) {
        int n=nums.length;

        for (int i=0; i<n; ++i){
            if (i == getDigitSum(nums[i])){
                return i;
            }
        }

        return -1;
    }
}