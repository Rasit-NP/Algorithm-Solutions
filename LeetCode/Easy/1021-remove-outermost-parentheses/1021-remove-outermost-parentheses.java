class Solution {
    public String removeOuterParentheses(String s) {
        int n = s.length();

        StringBuilder sb = new StringBuilder();

        for (int i=0, now=0; i<n; ++i){
            char c = s.charAt(i);

            if (c == '('){
                if (now++ > 0)
                    sb.append(c);
            }
            else{
                if (--now > 0)
                    sb.append(c);
            }
        }

        return sb.toString();
    }
}