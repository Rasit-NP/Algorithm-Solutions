class Solution {

    public int minCost(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        boolean[][][] dp = new boolean[n][m][1024];

        for (int i=0; i<n; ++i){
            for (int j=0; j<m; ++j){
                Arrays.fill(dp[i][j], false);
            }
        }

        dp[0][0][grid[0][0]] = true;

        int now = grid[0][0];
        for (int i=1; i<n; ++i){
            dp[i][0][now ^ grid[i][0]] = true;
            now ^= grid[i][0];
        }

        now = grid[0][0];
        for (int j=1; j<m; ++j){
            dp[0][j][now ^ grid[0][j]] = true;
            now ^= grid[0][j];
        }

        for (int i=1; i<n; ++i){
            for (int j=1; j<m; ++j){
                for (int bit=0; bit<1024; ++bit){
                    if (dp[i-1][j][bit]){
                        dp[i][j][bit^grid[i][j]] = true;
                    }
                    else if (dp[i][j-1][bit]){
                        dp[i][j][bit^grid[i][j]] = true;
                    }
                }
            }
        }

        for (int bit=0; bit<1024; ++bit){
            if (dp[n-1][m-1][bit])
                return bit;
        }

        return 0;
    }
}