# include <vector>
# include <string>
using namespace std;

class Solution {
private:
    int cnt, n, MAX;
    string basic;
    vector<vector<int>> state;
    vector<string> base;
    vector<vector<string>> ans;

    void backTrack(int p){
        int x = p/n, y = p%n;
        if (x == n){
            if (cnt == n){
                ans.push_back(base);
                return;
            }
            else {
                return;
            }
        }
        if (state[x][y] == 0){
            backTrack(p+1);

            state[x][y] += 1;
            base[x][y] = 'Q';
            for (int i=1; i<n-x; i++){
                int nx = x + i, ny;
                for (int dy : {-1, 0, 1}){
                    ny = y + dy*i;
                    if (nx >= n || ny < 0 || ny >= n){
                        continue;
                    }
                    state[nx][ny] += 1;
                }
            }
            ++cnt;
            backTrack((x+1)*n);
            --cnt;
            for (int i=1; i<n-x; i++){
                int nx = x + i, ny;
                for (int dy : {-1, 0, 1}){
                    ny = y + dy*i;
                    if (nx >= n || ny < 0 || ny >= n){
                        continue;
                    }
                    state[nx][ny] -= 1;
                }
            }
            base[x][y] = '.';
            state[x][y] -= 1;
        }
        else if (state[x][y] > 0){
            backTrack(p+1);
        }
    }
public:
    vector<vector<string>> solveNQueens(int N) {
        cnt = 0;
        n = N;
        MAX = n*n;
        state.assign(n, vector<int>(n, 0));
        basic.assign(n, '.');
        base.assign(n, basic);
        
        backTrack(0);

        return ans;
    }
};