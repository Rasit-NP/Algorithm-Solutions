class Solution {
    public int reverseDegree(String s) {
        int n = s.length();
        int res = 0;

        for (int i=0; i<n;){
            char c = s.charAt(i);

            int val = 26 - (c-'a');
            res += val * (++i);
        }

        return res;
    }
}