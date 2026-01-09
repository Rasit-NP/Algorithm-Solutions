# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
using namespace std;

int n;
vector<vector<pair<int, int>>> dxdy_pqbr(3, vector<pair<int, int>>(0));
vector<pair<int, int>> dxdy_n = {{2, 1}, {1, 2}, {-2, 1}, {-1, 2}, {2, -1}, {1, -2}, {-2, -1}, {-1, -2}};

bool position_check(int x, int y){
    if (x < 0 || x >= n || y < 0 || y >= n)
        return true;
    else
        return false;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n;
    int ans = -1;
    int x_start, y_start;
    vector<vector<char>> board(n, vector<char>(n, '0'));
    vector<vector<int>> visited(n, vector<int>(n, 3*n*n));
    dxdy_pqbr[0] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    dxdy_pqbr[1] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    dxdy_pqbr[2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    priority_queue<vector<int>> pq;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> board[i][j];
            if (board[i][j] == 'P'){
                x_start = i, y_start = j;
            }
        }
    }

    pq.push({0, x_start, y_start});
    visited[x_start][y_start] = 0;
    while (pq.size()){
        int dist = -pq.top()[0], x = pq.top()[1], y = pq.top()[2];
        char state = board[x][y];
        pq.pop();

        if (state == 'K'){
            ans = dist;
            break;
        }
        if (dist > visited[x][y])
            continue;
        if (state == 'P'){
            board[x][y] = '0';
            for (pair<int, int> dxdy : dxdy_pqbr[0]){
                int nx = x+dxdy.first, ny = y+dxdy.second;
                if (position_check(nx, ny))
                    continue;
                if (board[nx][ny] == '0')
                    continue;
                visited[nx][ny] = 1;
                pq.push({-1, nx, ny});
            }
        }
        else if (state == 'Q'){
            for (pair<int, int> dxdy : dxdy_pqbr[0]){
                for (int length = 1; length < n; length++){
                    int nx = x + length*dxdy.first, ny = y + length*dxdy.second;
                    if (position_check(nx, ny))
                        break;
                    if (board[nx][ny] == '0')
                        continue;
                    if (visited[nx][ny] > visited[x][y] + length){
                        visited[nx][ny] = visited[x][y] + length;
                        pq.push({-visited[nx][ny], nx, ny});
                    }
                    break;
                }
            }
        }
        else if (state == 'N'){
            for (pair<int, int> dxdy : dxdy_n){
                int nx = x + dxdy.first, ny = y + dxdy.second;
                if (position_check(nx, ny))
                    continue;
                if (board[nx][ny] == '0')
                    continue;
                if (visited[nx][ny] > visited[x][y] + 2){
                    visited[nx][ny] = visited[x][y] + 2;
                    pq.push({-visited[nx][ny], nx, ny});
                }
                
            }
        }
        else {
            int state_num = (state == 'B' ? 1 : 2);
            for (pair<int, int> dxdy : dxdy_pqbr[state_num]){
                for (int length = 1; length<n; length++){
                    int nx = x + length*dxdy.first, ny = y + length*dxdy.second;
                    if (position_check(nx, ny))
                        break;
                    if (board[nx][ny] == '0')
                        continue;
                    if (visited[nx][ny] > visited[x][y] + length){
                        visited[nx][ny] = visited[x][y] + length;
                        pq.push({-visited[nx][ny], nx, ny});
                    }
                    break;
                }
            }
        }
    }

    cout << ans << '\n';
}