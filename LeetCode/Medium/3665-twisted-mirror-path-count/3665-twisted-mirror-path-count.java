class Solution {
    private static final int MOD = 1_000_000_007;

    public int uniquePaths(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int[][][] dp = new int[n][m][2];

        for (int i=0; i<n; ++i){
            if (grid[i][0] == 1){
                dp[i][0][1] = 1;
                break;
            }
            else {
                dp[i][0][0] = 1;
            }
        }
        for (int j=0; j<m; ++j){
            if (grid[0][j] == 1){
                dp[0][j][0] = 1;
                break;
            }
            else {
                dp[0][j][1] = 1;
            }
        }

        for (int i=1; i<n; ++i){
            for (int j=1; j<m; ++j){
                if (grid[i-1][j] == 0){
                    dp[i][j][0] += dp[i-1][j][1];
                }
                dp[i][j][0] += dp[i-1][j][0];

                if (dp[i][j][0] > MOD)
                    dp[i][j][0] -= MOD;

                if (grid[i][j-1] == 0){
                    dp[i][j][1] += dp[i][j-1][0];
                }
                dp[i][j][1] += dp[i][j-1][1];

                if (dp[i][j][1] > MOD)
                    dp[i][j][1] -= MOD;

                if (grid[i][j] == 1){
                    swap(dp[i][j]);
                }
            }
        }

        return (dp[n-1][m-1][0] + dp[n-1][m-1][1]) % MOD;
    }

    private void swap(int[] pos){
        int tmp = pos[0];
        pos[0] = pos[1];
        pos[1] = tmp;
    }

    private void mod(int[] pos){
        if (pos[0] > MOD)
            pos[0] -= MOD;
        if (pos[1] > MOD)
            pos[1] -= MOD;
    }
}