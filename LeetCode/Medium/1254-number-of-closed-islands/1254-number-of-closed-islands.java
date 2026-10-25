import java.util.ArrayDeque;

class Solution {

    private record Position(int x, int y){}

    private int n, m;
    private int[][] visited;
    private final int[][] dxdys = new int[][]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    private boolean bfs(int[][] grid, int i, int j){
        ArrayDeque<Position> q = new ArrayDeque<>();

        boolean res = true;

        visited[i][j] = 1;
        q.addLast(new Position(i, j));

        while (q.size() > 0){
            Position now = q.peekFirst();      q.removeFirst();

            int x = now.x(), y = now.y();

            for (int[] dxdy : dxdys){
                int dx = dxdy[0], dy = dxdy[1];
                int nx = x + dx;
                int ny = y + dy;

                if (nx < 0 || nx >= n || ny < 0 || ny >= m){
                    res = false;
                    continue;
                }

                if (grid[nx][ny] == 1)
                    continue;

                if (visited[nx][ny] == 0){
                    visited[nx][ny] = 1;
                    q.addLast(new Position(nx, ny));
                }
            }
        }

        return res;
    }

    public int closedIsland(int[][] grid) {
        n = grid.length;
        m = grid[0].length;
        visited = new int[n][m];

        int res = 0;

        for (int i=0; i<n; ++i){
            for (int j=0; j<m; ++j){
                if (grid[i][j] == 1)
                    continue;
                
                if (visited[i][j] == 0){
                    res += (bfs(grid, i, j) ? 1 : 0);
                }
            }
        }

        return res;
    }
}