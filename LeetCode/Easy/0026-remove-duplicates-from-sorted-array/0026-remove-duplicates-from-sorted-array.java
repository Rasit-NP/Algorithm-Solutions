class Solution {
    public int removeDuplicates(int[] nums) {
        int n = nums.length;

        int k = 0;

        for (int i=0; i<n;){
            int num = nums[i];
            int j = i + 1;

            while (j < n && num == nums[j]){
                nums[j++] = 101;
            }

            i = j;
            ++k;
        }

        Arrays.sort(nums);

        return k;
    }
}