import java.util.ArrayDeque;

class Solution {
    public int uniquePaths(int n, int m) {
        int[][] dp = new int[n][m];
        int[][] passed = new int[n][m];
        dp[0][0] = 1;

        ArrayDeque<Integer[]> q = new ArrayDeque<>();

        q.addLast(new Integer[]{0, 0});
        while (q.size() > 0){
            Integer[] pos = q.peekFirst();  q.removeFirst();
            int x = pos[0], y = pos[1];

            if (passed[x][y] == 1)
                continue;

            int nx = x + 1, ny = y + 1;

            if (nx < n){
                dp[nx][y] += dp[x][y];
                q.addLast(new Integer[]{nx, y});
            }
            if (ny < m){
                dp[x][ny] += dp[x][y];
                q.addLast(new Integer[]{x, ny});
            }

            passed[x][y] = 1;
        }

        return dp[n-1][m-1];
    }
}