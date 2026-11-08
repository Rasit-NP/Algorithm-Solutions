import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;

class Solution {
    public int countServers(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        Set<Integer> communicatedServers = new HashSet<>();

        for (int i=0; i<n; ++i){
            List<Integer> servers = new ArrayList<>();

            for (int j=0; j<m; ++j){
                if (grid[i][j] == 1)
                    servers.add(m*i + j);
            }

            if (servers.size() > 1){
                communicatedServers.addAll(servers);
            }
        }

        for (int j=0; j<m; ++j){
            List<Integer> servers = new ArrayList<>();

            for (int i=0; i<n; ++i){
                if (grid[i][j] == 1)
                    servers.add(m*i + j);
            }

            if (servers.size() > 1){
                communicatedServers.addAll(servers);
            }
        }

        return communicatedServers.size();
    }
}