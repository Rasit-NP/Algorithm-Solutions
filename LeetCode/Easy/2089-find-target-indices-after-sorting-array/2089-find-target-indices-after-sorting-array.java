import java.util.List;
import java.util.ArrayList;

class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {
        Arrays.sort(nums);
        List<Integer> res = new ArrayList<>();

        for (int i=0, n=nums.length; i<n; ++i){
            if (nums[i] == target){
                res.add(i);
            }
        }

        return res;
    }
}