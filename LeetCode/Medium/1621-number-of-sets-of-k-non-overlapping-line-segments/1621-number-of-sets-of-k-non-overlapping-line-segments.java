class Solution {
    
    private int[][] dp;
    private int[][] sum;
    private final int MAX = 1_000_000_007;

    private int get(int n, int k){
        if (k == 0)
            return 1;
        if (n <= 0)
            return 0;
        if (dp[n][k] != -1)
            return dp[n][k];
        
        int res = get(n-1, k);

        res += getSum(n-1, k-1);
        if (res >= MAX)
            res -= MAX;
        
        dp[n][k] = res;
        return res;
    }

    private int getSum(int n, int k){
        if (n < 0)
            return 0;
        if (sum[n][k] != -1)
            return sum[n][k];

        int res = get(n, k) + getSum(n-1, k);
        if (res >= MAX)
            res -= MAX;

        sum[n][k] = res;

        return res;
    }

    public int numberOfSets(int n, int k) {
        dp = new int[n][k+1];
        sum = new int[n][k+1];

        for (int i=0; i<n; i++){
            Arrays.fill(dp[i], -1);
            Arrays.fill(sum[i], -1);
        }

        for (int i=0; i<n; i++){
            dp[i][0] = 1;
        }

        return get(n-1, k);
    }
}