class Solution {
    public boolean uniformArray(int[] nums) {
        Arrays.sort(nums);

        if ((nums[0]&1) == 0){
            for (int num : nums){
                if ((num&1) == 1)
                    return false;
            }
        }
        return true;
    }
}