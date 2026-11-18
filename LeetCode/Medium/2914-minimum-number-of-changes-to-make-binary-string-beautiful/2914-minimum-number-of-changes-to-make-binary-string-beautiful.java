class Solution {
    public int minChanges(String s) {
        int n = s.length();
        int res = 0;

        for (int i=0; 2*i<n; ++i){
            res += (s.charAt(2*i) == s.charAt(2*i+1) ? 0 : 1);
        }

        return res;
    }
}