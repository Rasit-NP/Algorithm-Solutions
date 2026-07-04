class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        int[] count = new int[n+1];

        for (int num : nums){
            count[num]++;
        }

        int sz = 0;
        for (int i=1; i<=n; i++){
            if (count[i] == 0 || count[i] >= 2){
                ++sz;
            }
        }

        int idx = 0;
        int[] res = new int[sz];
        for (int i=1; i<=n; i++){
            if (count[i] >= 2){
                res[idx++] = i;
            }
        }
        for (int i=1; i<=n; i++){
            if (count[i] == 0){
                res[idx++] = i;
            }
        }

        return res;
    }
}