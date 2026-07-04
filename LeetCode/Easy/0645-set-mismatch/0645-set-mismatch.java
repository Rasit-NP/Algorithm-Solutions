class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        int[] count = new int[n+1];

        for (int num : nums){
            count[num]++;
        }

        int[] res = new int[2];
        for (int i=1; i<=n; i++){
            if (count[i] >= 2){
                res[0] = i;
            }
            else if (count[i] == 0){
                res[1] = i;
            }
        }

        return res;
    }
}