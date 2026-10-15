import java.util.List;
import java.util.Set;
import java.util.HashSet;

class Solution {
    public int sumCounts(List<Integer> nums) {
        int n = nums.size();
        int res = 0;

        for (int i=0; i<n; ++i){
            for (int j=0; j<n; ++j){
                Set<Integer> set = new HashSet<>();
                for (int x=i; x<=j; ++x){
                    set.add(nums.get(x));
                }
                res += set.size() * set.size();
            }
        }

        return res;
    }
}