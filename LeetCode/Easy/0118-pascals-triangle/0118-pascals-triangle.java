class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<>();

        for (int i=0; i<numRows; ++i){
            if (i == 0){
                res.add(new ArrayList<>());
                res.get(0).add(1);
            }
            else {
                List<Integer> now = new ArrayList<>();
                List<Integer> before = res.get(i-1);
                now.add(1);
                for (int j=0; j<i-1; ++j){
                    now.add(before.get(j) + before.get(j+1));
                }
                now.add(1);
                res.add(now);
            }
        }

        return res;
    }
}