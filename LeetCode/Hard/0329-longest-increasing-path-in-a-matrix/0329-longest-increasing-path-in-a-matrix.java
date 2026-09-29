class Solution {

    private int n, m;
    private int[][] memo;
    private int[][] dxdys = new int[][]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    private int get(int[][] matrix, int x, int y){
        if (memo[x][y] > 0){
            return memo[x][y];
        }

        int res = 1;

        for (int[] dxdy : dxdys){
            int nx = x + dxdy[0];
            int ny = y + dxdy[1];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m){
                continue;
            }

            if (matrix[x][y] < matrix[nx][ny]){
                res = Math.max(res, get(matrix, nx, ny) + 1);
            }
        }

        memo[x][y] = res;

        return res;   
    }

    public int longestIncreasingPath(int[][] matrix) {
        n = matrix.length;
        m = matrix[0].length;

        memo = new int[n][m];

        int res = 0;

        for (int i=0; i<n; ++i){
            for (int j=0; j<m; ++j){
                res = Math.max(res, get(matrix, i, j));
            }
        }

        return res;
    }
}