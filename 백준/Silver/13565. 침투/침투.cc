# include <iostream>
# include <vector>
# include <queue>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n, m;   cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<pair<int, int>> dxdys = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            char input; cin >> input;
            if (input == '1')
                board[i][j] = 1;
            else
                board[i][j] = 0;
        }
    }

    queue<pair<int, int>> q;
    for (int j=0; j<m; j++){
        if (board[0][j] == 0){
            q.push({0, j});
            visited[0][j] = 0;
        }
    }
    bool res = false;
    while (q.size()){
        pair<int, int> now = q.front(); q.pop();
        int x = now.first, y = now.second;
        if (x == n-1){
            res = true;
            break;
        }

        for (pair<int, int> dxdy : dxdys){
            int nx = x + dxdy.first, ny= y + dxdy.second;
            if (nx<0 || nx>=n || ny<0 || ny>=m || board[nx][ny])
                continue;
            if (visited[nx][ny])
                continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    if (res)    cout << "YES";
    else        cout << "NO";
}