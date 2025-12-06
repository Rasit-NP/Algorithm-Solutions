# include <iostream>
# include <vector>
# include <queue>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    sx--; sy--; ex--; ey--;
    
    vector<vector<vector<int>>> visited(3, vector<vector<int>>(n, vector<int>(m, 1<<30)));
    vector<vector<int>> board(n, vector<int>(m, 0));
    vector<vector<pair<int, int>>> dxdy;
    dxdy.push_back({{1, 0}, {0, 1}, {-1, 0}, {0, -1}});
    dxdy.push_back({{1, 0}, {-1, 0}});
    dxdy.push_back({{0, 1}, {0, -1}});
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    priority_queue<vector<int>> heap;
    vector<int> data(4, 0);  // 충격량, x, y, t
    data[0] = 0; data[1] = sx; data[2] = sy;
    heap.push(data);
    visited[0][sx][sy] = 0;

    int ans = -1;
    while (heap.size()){
        vector<int> now = heap.top();
        heap.pop();
        int val = -now[0];
        int x = now[1], y = now[2];
        int t = now[3];
        int nt = (t+1)%3;
        if (x == ex && y == ey){
            ans = val;
            break;
        }

        if (visited[t%3][x][y] < val) continue;
        for (pair<int, int> delta : dxdy[nt]){
            int nx = x+delta.first, ny = y+delta.second;
            if (!(nx>=0 && nx<n && ny>=0 && ny<m) || board[nx][ny] == -1)  continue;
            if (visited[nt][nx][ny] > val + board[nx][ny]){
                visited[nt][nx][ny] = val + board[nx][ny];
                data[0] = -visited[nt][nx][ny];
                data[1] = nx, data[2] = ny, data[3] = t+1;
                heap.push(data);
            }
        }
    }
    cout << ans << '\n';
}