# include <iostream>
# include <vector>
# include <queue>
# include <unordered_set>
using namespace std;
using pii = pair<int, int>;

vector<pii> dxdys = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct Data{
    int value;
    vector<pii> positions;

    Data(int value): value(value){
    }

    void add(int x, int y){
        positions.emplace_back(x, y);
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n, m;   cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m));
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<Data> dataSet;

    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            cin >> board[i][j];
        }
    }

    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            if (visited[i][j])
                continue;
            Data data = Data(board[i][j]);
            queue<pii> q;
            q.emplace(i, j);
            visited[i][j] = 1;
            data.add(i, j);

            while (q.size()){
                pii position = q.front();   q.pop();
                int x = position.first, y = position.second;
                for (const auto& [dx, dy] : dxdys){
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    if (visited[nx][ny])
                        continue;
                    if (board[x][y] != board[nx][ny])
                        continue;
                    q.emplace(nx, ny);
                    visited[nx][ny] = 1;
                    data.add(nx, ny);
                }
            }
            dataSet.push_back(data);
        }
    }

    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            cin >> board[i][j];
        }
    }

    int changed = 0;

    for (Data& data : dataSet){
        unordered_set<int> values;
        
        for (const auto& [x, y] : data.positions){
            values.insert(board[x][y]);
        }

        if (values.size() != 1){
            cout << "NO\n";
            return 0;
        }
        if (data.value != *values.begin())
            ++changed;
    }

    cout << (changed <= 1 ? "YES" : "NO") << '\n';
}