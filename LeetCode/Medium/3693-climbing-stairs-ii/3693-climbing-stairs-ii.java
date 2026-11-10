class Solution {
    public int climbStairs(int n, int[] costs) {
        int[] dp = new int[n+1];

        Arrays.fill(dp, 1<<30);
        dp[0] = 0;

        for (int i=0; i<n; ++i){
            for (int di=1; di<=3; ++di){
                int ni = i + di;
                if (ni > n)
                    break;
                dp[ni] = Math.min(dp[ni], dp[i] + costs[ni-1] + di*di);
            }
        }

        return dp[n];
    }
}