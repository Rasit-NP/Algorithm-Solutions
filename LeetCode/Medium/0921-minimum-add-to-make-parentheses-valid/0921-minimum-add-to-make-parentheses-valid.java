class Solution {
    public int minAddToMakeValid(String s) {
        int count = 0;
        int n = s.length();

        int res = 0;

        for (int i=0; i<n; ++i){
            char c = s.charAt(i);

            if (c == '(')
                ++count;
            else
                --count;

            if (count < 0){
                res += Math.abs(count);
                count = 0;
            }
        }

        return res + Math.abs(count);
    }
}