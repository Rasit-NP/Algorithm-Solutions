# include <vector>
using namespace std;

class Solution {
public:

    pair<int, int> find(int x, int y, vector<vector<pair<int, int>>>& direction, int move){
        for (int i=0; i<move; i++){
            int dx = direction[x][y].first, dy = direction[x][y].second;
            
            x += dx;
            y += dy;
        }

        return {x, y};
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        vector<vector<pair<int, int>>> direction(n, vector<pair<int, int>>(m));

        for (int i=0; i<min(n, m)/2; i++){
            int x = i, y = i;
            int dx = 1, dy = 0;
            vector<int> nums;
            nums.push_back(grid[x][y]);
            direction[x][y] = {dx, dy};
            x += dx;
            y += dy;
            while (x != i || y != i){
                nums.push_back(grid[x][y]);
                if (x+dx < i || y+dy < i || x+dx > (n-1)-i || y+dy > (m-1)-i){
                    swap(dx, dy);
                    dx *= -1;
                }

                direction[x][y] = {dx, dy};

                x += dx;
                y += dy;
            }

            int limit = 2*n+2*m-8*i-4;
            int move = k % limit;
            x = i, y = i;
            dx = direction[x][y].first, dy = direction[x][y].second;

            pair<int, int> after = find(x, y, direction, move);
            int nx = after.first, ny = after.second;

            for (int d=0; d<limit; d++){
                pair<int, int>& delta = direction[nx][ny];
                ans[nx][ny] = nums[d];
                nx += delta.first;
                ny += delta.second;
            }
        }

        return ans;
    }
};