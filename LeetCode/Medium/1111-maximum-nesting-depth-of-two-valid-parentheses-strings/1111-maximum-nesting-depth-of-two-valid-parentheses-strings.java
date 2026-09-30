class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int n = seq.length();

        int nowDepth = 0;
        int[] res = new int[n];

        for (int i=0; i<n; ++i){
            char c = seq.charAt(i);

            if (c == '('){
                res[i] = ++nowDepth & 1;
            }
            else {
                res[i] = nowDepth-- & 1;
            }
        }

        return res;
    }
}