class Solution {
    public int maxDepth(String s) {
        int res = 0;
        int now = 0;

        int n = s.length();

        for (int i=0; i<n; ++i){
            char c = s.charAt(i);

            if (c == '('){
                ++now;
                res = Math.max(res, now);
            }
            else if (c == ')')
                --now;
        }

        return res;
    }
}