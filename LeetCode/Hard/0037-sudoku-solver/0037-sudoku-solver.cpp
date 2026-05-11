# include <vector>
using namespace std;

class Solution {
private:

    int cntBlank = 0;
    vector<pair<int, int>> blanks;
    bool fin = false;

    void backTrack(vector<vector<char>>& board, int idx){
        if (idx == blanks.size()){
            fin = true;
            return;
        }
        int x = blanks[idx].first, y = blanks[idx].second;

        int available = (1<<10) - 1;
        for (int i=0; i<9; i++){
            if (board[x][i] != '.'){
                int num = (board[x][i] - '0');
                if (available & (1 << num)){
                    available -= (1 << num);
                }
            }
            if (board[i][y] != '.'){
                int num = (board[i][y] - '0');
                if (available & (1 << num)){
                    available -= (1 << num);
                }
            }
        }
        int nx = (x/3)*3, ny = (y/3)*3;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                if (board[nx+i][ny+j] != '.'){
                    int num = (board[nx+i][ny+j] - '0');
                    if (available & (1 << num)){
                        available -= (1 << num);
                    }
                }
            }
        }
        for (int i=1; i<=9; i++){
            if (available & (1 << i)){
                board[x][y] = i + '0';
                backTrack(board, idx+1);
                if (fin){
                    return;
                }
                board[x][y] = '.';
            }
        }
    }

public:

    void solveSudoku(vector<vector<char>>& board) {
        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                if (board[i][j] == '.'){
                    blanks.emplace_back(i, j);
                }
            }
        }
        cntBlank = blanks.size();

        backTrack(board, 0);
    }
};