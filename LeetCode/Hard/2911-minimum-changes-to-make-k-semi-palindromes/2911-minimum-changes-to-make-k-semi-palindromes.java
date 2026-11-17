class Solution {
    public int minimumChanges(String s, int k) {
        int n = s.length();

        int[][] cost = new int[n][n];

        for (int i=0; i<n; ++i){
            for (int j=i+1; j<n; ++j){
                cost[i][j] = getCost(s, i, j);
            }
        }

        int[][] dp = new int[k+1][n+1];

        for (int[] row : dp){
            Arrays.fill(row, 1<<30);
        }
        dp[0][0] = 0;

        for (int l=1; l<=k; ++l){
            for (int i=2*l; i<=n; ++i){
                for (int j=2*(l-1); j<=i-2; ++j){
                    dp[l][i] = Math.min(dp[l][i], dp[l-1][j] + cost[j][i-1]);
                }
            }
        }

        return dp[k][n];
    }

    private int getCost(String s, int l, int r){
        int len = r - l + 1;
        int res = 1<<30;

        for (int d=1; d*2<=len; ++d){
            if (len % d != 0)
                continue;

            int m = len / d;
            int cnt = 0;

            for (int g=0; g<d; ++g){
                for (int t=0; t<m/2; ++t){
                    if (s.charAt(l + g + t*d) != s.charAt(l + g + (m-1-t)*d))
                        ++cnt;
                }
            }

            res = Math.min(res, cnt);
        }

        return res;
    }
}