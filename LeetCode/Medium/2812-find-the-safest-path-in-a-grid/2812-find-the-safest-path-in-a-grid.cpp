# include <vector>
# include <queue>
# include <cmath>
# include <algorithm>
using namespace std;

class Solution {
private:
    int n, m;
    vector<pair<int, int>> dxdys = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<int>> factor;

    bool check(int stdFactor, vector<vector<int>>& grid){
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        if (factor[0][0] >= stdFactor){
            visited[0][0] = 1;
            q.emplace(0, 0);
        }

        while (q.size()){
            const auto [x, y] = q.front(); q.pop();

            for (const auto& [dx, dy] : dxdys){
                int nx = x + dx, ny = y + dy;

                if (nx < 0 || nx >= n || ny < 0 || ny >= m){
                    continue;
                }
                if (factor[nx][ny] < stdFactor || visited[nx][ny]){
                    continue;
                }

                visited[nx][ny] = 1;
                q.emplace(nx, ny);
            }
        }
        
        return visited[n-1][m-1];
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        factor.assign(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j] == 1){
                    factor[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }

        while (q.size()){
            const auto [x, y] = q.front();  q.pop();

            for (const auto& [dx, dy] : dxdys){
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m){
                    continue;
                }
                if (factor[nx][ny] < INT_MAX){
                    continue;
                }

                factor[nx][ny] = factor[x][y] + 1;
                q.emplace(nx, ny);
            }
        }

        int l = -1, r = n + m;

        while (r-l > 1){
            int mid = (l+r)/2;

            if (check(mid, grid)){
                l = mid;
            }
            else {
                r = mid;
            }
        }

        return l;
    }
};