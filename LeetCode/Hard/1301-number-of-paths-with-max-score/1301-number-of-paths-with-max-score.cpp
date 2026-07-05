# include <vector>
# include <string>
using namespace std;

class Solution {
private:
    int n;
    vector<string> board;
    vector<vector<pair<int, int>>> dp;
    vector<pair<int, int>> dxdy = {{-1, 0}, {0, -1}, {-1, -1}};

    pair<int, int>& dfs(int x, int y){
        pair<int, int>& now = dp[x][y];
        if (x == 0 && y == 0){
            return now;
        }
        if (now.first != -1 || now.second != -1){
            return now;
        }

        int maxVal = 0, maxPath = 0;

        for (const auto& [dx, dy] : dxdy){
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || ny < 0){
                continue;
            }
            if (board[nx][ny] == 'X'){
                continue;
            }
            pair<int, int>& next = dfs(nx, ny);
            if (next.first > maxVal){
                maxVal = next.first;
                maxPath = next.second;
            }
            else if (next.first == maxVal){
                maxPath += next.second;
                maxPath %= 1'000'000'007;
            }
        }

        now = {maxVal, maxPath};
        if (maxPath == 0){
            now = {0, 0};
        }
        else if (x != n-1 || y != n-1){
            now.first += (board[x][y] - '0');
        }
        return now;
    }
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        this->board = board;
        dp.assign(n, vector<pair<int, int>>(n, {-1, -1}));

        dp[0][0] = {0, 1};
        pair<int, int>& res = dfs(n-1, n-1);

        return {res.first, res.second};
    }
};