import java.util.ArrayDeque;

class Solution {

    private record Position(int x, int y){}

    private int n, m;
    private boolean[][] visited;
    private static final int[][] dxdys = new int[][]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    private long bfs(int[][] grid, int i, int j){
        long totalVal = grid[i][j];
        visited[i][j] = true;

        ArrayDeque<Position> q = new ArrayDeque<>();
        q.addLast(new Position(i, j));

        while (q.size() > 0){
            Position now = q.peekFirst();   q.removeFirst();
            int x = now.x(), y = now.y();

            for (int[] dxdy : dxdys){
                int nx = x + dxdy[0];
                int ny = y + dxdy[1];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                
                if (grid[nx][ny] == 0 || visited[nx][ny])
                    continue;

                visited[nx][ny] = true;
                totalVal += grid[nx][ny];
                q.addLast(new Position(nx, ny));
            }
        }

        return totalVal;
    }

    public int countIslands(int[][] grid, int k) {
        n = grid.length;
        m = grid[0].length;

        visited = new boolean[n][m];

        int res = 0;

        for (int i=0; i<n; ++i){
            for (int j=0; j<m; ++j){
                if (grid[i][j] != 0 && !visited[i][j]){
                    long totalVal = bfs(grid, i, j);
                    res += (totalVal % k == 0 ? 1 : 0);
                }
            }
        }

        return res;
    }
}