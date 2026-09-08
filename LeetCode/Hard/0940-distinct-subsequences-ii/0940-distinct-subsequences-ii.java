class Solution {
    final private int MAX = 1_000_000_007;

    public int distinctSubseqII(String s) {
        int n = s.length();

        int[] dp = new int[26];

        int total = 0;

        for (int i=0; i<n; i++){
            char c = s.charAt(i);
            int idx = c - 'a';

            int tmp = dp[idx];

            dp[idx] = total + 1;
            if (dp[idx] > MAX)
                dp[idx] -= MAX;
            total += (dp[idx] >= tmp ? dp[idx] - tmp : dp[idx] - tmp + MAX);
            if (total > MAX)
                total -= MAX;
        }

        return total;
    }
}