# include<iostream>
# include <vector>
# include <queue>
# include <string>
using namespace std;

vector<pair<int, int>> dS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void run(int& tc){
    vector<string> table(16);
    pair<int, int> start, end;
    vector<vector<bool>> visited(16, vector<bool>(16, false));
    queue<pair<int, int>> q;

    for (int i=0; i<16; i++){
        cin >> table[i];
        for (int j=0; j<16; j++){
            if (table[i][j] == '2'){
                start = {i, j};
            }
            else if (table[i][j] == '3'){
                end = {i, j};
            }
        }
    }

    q.push(start);
    visited[start.first][start.second] = true;

    while (q.size()){
        int x = q.front().first, y = q.front().second;  q.pop();
        if (x == end.first && y == end.second){
            break;
        }
        for (const auto& dxdy : dS){
            int dx = dxdy.first, dy = dxdy.second;
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || nx >= 16 || ny < 0 || ny >= 16){
                continue;
            }
            if (table[nx][ny] != '1' && visited[nx][ny] == false){
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    cout << "#" << tc << ' ';
    cout << (visited[end.first][end.second] ? 1 : 0) << '\n';
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int tc;
    while (cin >> tc){
        run(tc);
    }
	return 0;
}