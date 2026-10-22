class Solution {
    public int minOperations(int[] nums) {
        int increaseCount = 0, decreaseCount = 0;
        int n = nums.length;
        int minIdx = 0;

        for (int i=0; i<n; ++i){
            int num = nums[i];
            if (num == 0)
                minIdx = i;
            
            if (i == 0){
                if (num < nums[n-1]){
                    ++decreaseCount;
                }
                else {
                    ++increaseCount;
                }
            }
            else {
                if (num < nums[i-1]){
                    ++decreaseCount;
                }
                else {
                    ++increaseCount;
                }
            }
        }

        if (n == 1){
            return 0;
        }
        else if (n == 2){
            return (nums[0] == 0 ? 0 : 1);
        }
        else if (increaseCount != 1 && decreaseCount != 1){
            return -1;
        }
        else if (increaseCount > decreaseCount){
            return Math.min(minIdx, n-minIdx+2);
        }
        else {
            return Math.min(minIdx+2, n-minIdx);
        }
    }
}