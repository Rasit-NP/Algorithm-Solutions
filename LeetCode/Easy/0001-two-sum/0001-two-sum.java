import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        Map<Integer, Integer> visited = new HashMap<>();

        for (int i=0; i<n; i++){
            int num = nums[i];
            int t = target - num;

            if (visited.containsKey(t)){
                return new int[]{visited.get(t), i};
            }
            else {
                visited.put(num, i);
            }
        }

        return new int[2];
    }
}