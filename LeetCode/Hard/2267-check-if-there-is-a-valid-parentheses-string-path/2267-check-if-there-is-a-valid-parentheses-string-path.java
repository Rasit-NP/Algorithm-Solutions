import java.util.ArrayDeque;

class Solution {

    private int[][] dxdys = new int[][]{{1, 0}, {0, 1}};
    private record Data(int cnt, int x, int y){}

    public boolean hasValidPath(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int[][][] visited = new int[n+m][n][m];
        ArrayDeque<Data> dq = new ArrayDeque<>();
        if (grid[0][0] == '('){
            visited[1][0][0] = 1;
            dq.addLast(new Data(1, 0, 0));
        }
        
        while (dq.size() > 0){
            Data now = dq.peekFirst();  dq.removeFirst();

            int cnt = now.cnt;
            int x = now.x; int y = now.y;

            for (int[] dxdy : dxdys){
                int dx = dxdy[0], dy = dxdy[1];
                int nx = x + dx, ny = y + dy;

                if (nx >= n || ny >= m)
                    continue;
                
                int newCnt = cnt + (grid[nx][ny] == '(' ? 1 : -1);
                if (newCnt < 0)
                    continue;
                
                if (visited[newCnt][nx][ny] > 0)
                    continue;
                
                visited[newCnt][nx][ny] = 1;
                dq.addLast(new Data(newCnt, nx, ny));
            }
        }

        return visited[0][n-1][m-1] == 1;
    }
}