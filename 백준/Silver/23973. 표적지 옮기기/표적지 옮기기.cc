# include <iostream>
# include <vector>
# include <string>
# include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> board;
vector<pair<int, int>> holes;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n >> m;
    board.assign(n, vector<int>(m, 0));
    for (int i=0; i<n; i++){
        string line;    cin >> line;
        for (int j=0; j<m; j++){
            if (line[j] == '1'){
                holes.push_back({i, j});
                board[i][j] = 1;
            }
        }
    }

    for (int i=0; i<holes.size(); i++){
        int x = holes[i].first, y = holes[i].second;
        vector<int> table(10, 0);
        table[0] = 1;
        for (int dx=-9; dx<10; dx++){
            for (int dy=-9; dy<10; dy++){
                if (dx == 0 && dy == 0) continue;
                int nx = x+dx, ny = y+dy;
                if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if (board[nx][ny] == 1){
                    table[max(abs(nx-x), abs(ny-y))]++;
                }
            }
        }
        bool check = true;
        for (int a : table){
            if (a != 1){
                check = false;
                break;
            }
        }
        if (check){
            cout << x << ' ' << y;
            return 0;
        }
    }
    cout << -1;
    return 0;
}