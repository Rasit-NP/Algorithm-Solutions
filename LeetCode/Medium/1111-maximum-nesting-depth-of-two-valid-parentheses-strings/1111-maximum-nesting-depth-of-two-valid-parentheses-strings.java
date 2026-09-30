class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int n = seq.length();
        int[] depth = new int[n];

        int nowDepth = 0;
        int maxDepth = 0;
        for (int i=0; i<n; ++i){
            char c = seq.charAt(i);
            if (i == 0 && c == '('){
                depth[0] = ++nowDepth;
                maxDepth = 1;
            }
            else if (c == '('){
                depth[i] = ++nowDepth;
                maxDepth = Math.max(maxDepth, depth[i]);
            }
            else {
                depth[i] = nowDepth--;
            }
        }

        int[] res = new int[n];
        for (int i=0; i<n; ++i){
            int val = depth[i];
            if (val > maxDepth/2)
                res[i] = 1;
        }

        return res;
    }
}