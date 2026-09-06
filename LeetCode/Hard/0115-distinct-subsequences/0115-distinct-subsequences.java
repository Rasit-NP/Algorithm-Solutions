class Solution {
    public int numDistinct(String s, String t) {
        int n1 = s.length();
        int n2 = t.length();

        long[][] dp = new long[n2][n1];

        dp[0][0] = (s.charAt(0) == t.charAt(0) ? 1 : 0);

        for (int j=1; j<n1; ++j){
            dp[0][j] = dp[0][j-1] + (t.charAt(0) == s.charAt(j) ? 1 : 0);
        }

        for (int i=1; i<n2; ++i){
            for (int j=1; j<n1; ++j){
                dp[i][j] = dp[i][j-1] + (t.charAt(i) == s.charAt(j) ? dp[i-1][j-1] : 0);
                dp[i][j] %= Integer.MAX_VALUE;
            }
        }

        return (int)dp[n2-1][n1-1];
    }
}