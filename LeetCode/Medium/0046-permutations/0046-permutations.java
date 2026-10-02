import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;

class Solution {

    private int n;
    private int[] nums;
    private final List<List<Integer>> res = new ArrayList<>();
    private final List<Integer> now = new ArrayList<>();
    private final Set<Integer> set = new HashSet<>();

    private void backtrack(){
        if (now.size() == n){
            List<Integer> tmp = new ArrayList<>();

            for (int i=0; i<n; ++i){
                tmp.add(now.get(i));
            }

            res.add(tmp);
            return;
        }

        for (int num : nums){
            if (!set.contains(num)){
                set.add(num);
                now.add(num);
                backtrack();
                now.remove(now.size() - 1);
                set.remove(num);
            }
        }
    }

    public List<List<Integer>> permute(int[] nums) {
        this.n = nums.length;
        this.nums = nums;
        
        backtrack();

        return res;
    }
}