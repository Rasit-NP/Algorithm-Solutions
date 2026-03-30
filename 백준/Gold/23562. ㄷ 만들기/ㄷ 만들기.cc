# include <iostream>
# include <vector>
# include <climits>
# include <algorithm>
using namespace std;

int n, m;
int a, b;
vector<vector<char>> board;
vector<vector<char>> guide(3, vector<char>(3));

int cal(int& x, int& y, int& len){
    int res = 0;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (!(i>=x && i<x+3*len && j>=y && j<y+3*len)){
                res += b * (board[i][j] == '#' ? 1 : 0);
            }
            else {
                int nx = (i-x)/len;
                int ny = (j-y)/len;
                if (board[i][j] == guide[nx][ny]){
                    continue;
                }
                res += (board[i][j] == '#' ? b : a);
            }
        }
    }
    return res;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n >> m;
    cin >> a >> b;

    board.assign(n, vector<char>(m));
    guide = {{'#', '#', '#'}, {'#', '.', '.'}, {'#', '#', '#'}};

    for (vector<char>& row : board){
        for (char& c : row){
            cin >> c;
        }
    }

    int ans = INT_MAX;
    for (int len=1; len<=6; len++){
        for (int x=0; x+3*len <= n; x++){
            for (int y=0; y+3*len <= m; y++){
                ans = min(ans, cal(x, y, len));
            }
        }
    }

    cout << ans;
}