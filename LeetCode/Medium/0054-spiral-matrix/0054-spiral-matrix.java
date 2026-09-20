class Solution {

    private int[] rotate(int[] direction){
        int dx = direction[0];
        int dy = direction[1];

        return new int[]{dy, -dx};
    }

    public List<Integer> spiralOrder(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        int x = 0;
        int y = 0;
        int cnt = n*m;
        int[] nowDirection = new int[]{0, 1};
        int[][] visited = new int[n][m];
        List<Integer> res = new ArrayList<>();

        while (cnt-- > 0){
            visited[x][y] = 1;
            res.add(matrix[x][y]);

            int nx = x + nowDirection[0];
            int ny = y + nowDirection[1];

            if (Math.min(nx, ny) < 0 || nx >= n || ny >= m || visited[nx][ny] == 1){
                int[] newDirection = rotate(nowDirection);
                nowDirection[0] = newDirection[0];
                nowDirection[1] = newDirection[1];
            }

            x += nowDirection[0];
            y += nowDirection[1];
        }

        return res;
    }
}