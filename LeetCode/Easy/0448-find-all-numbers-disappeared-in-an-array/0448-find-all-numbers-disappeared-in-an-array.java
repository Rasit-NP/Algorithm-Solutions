import java.util.List;
import java.util.Arrays;

class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int n = nums.length;
        List<Integer> res = new ArrayList<>();
        int[] count = new int[n+1];

        for (int num : nums){
            count[num]++;
        }

        for (int i=1; i<=n; i++){
            if (count[i] == 0){
                res.add(i);
            }
        }
        
        return res;
    }
}