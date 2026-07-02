# include <vector>
# include <queue>
# include <climits>
using namespace std;

vector<pair<int, int>> dxdys = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<vector<int>> pq;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        if (grid[0][0]){
            --health;
        }

        pq.push({health, 0, 0});
        visited[0][0] = health;

        while (pq.size()){
            vector<int> v = pq.top();   pq.pop();

            int now = v[0], x = v[1], y = v[2];
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
                    pq.push({now-1, nx, ny});
                }
                else if (grid[nx][ny] == 0 && visited[nx][ny] < now){
                    visited[nx][ny] = now;
                    pq.push({now, nx, ny});
                }
            }
        }

        return false;
    }
};