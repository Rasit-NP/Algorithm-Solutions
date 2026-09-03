import java.util.List;

class Solution {
    public List<String> buildArray(int[] targets, int n) {
        List<String> res = new ArrayList<>();

        int idx = 0;
        for (int num=1; num<=n; num++){
            if (idx >= targets.length)
                break;
            if (targets[idx] > num){
                res.add("Push");
                res.add("Pop");
            }
            else if (targets[idx] == num){
                res.add("Push");
                ++idx;
            }
        }

        return res;
    }
}