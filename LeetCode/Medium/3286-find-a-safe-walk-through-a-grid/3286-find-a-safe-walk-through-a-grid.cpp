# include <vector>
# include <deque>
# include <climits>
using namespace std;

vector<pair<int, int>> dxdys = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        deque<pair<int, int>> dq;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        if (grid[0][0]){
            --health;
        }

        dq.push_back({0, 0});
        visited[0][0] = health;

        while (dq.size()){
            const auto [x, y] = dq.front();   dq.pop_front();
            int now = visited[x][y];

            if (x == n-1 && y == m-1){
                return true;
            }
            
            for (const auto& [dx, dy] : dxdys){
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m){
                    continue;
                }
                if (grid[nx][ny] && now > 1 && visited[nx][ny] < now-1){
                    visited[nx][ny] = now - 1;
                    dq.push_back({nx, ny});
                }
                else if (grid[nx][ny] == 0 && visited[nx][ny] < now){
                    visited[nx][ny] = now;
                    dq.push_front({nx, ny});
                }
            }
        }

        return false;
    }
};