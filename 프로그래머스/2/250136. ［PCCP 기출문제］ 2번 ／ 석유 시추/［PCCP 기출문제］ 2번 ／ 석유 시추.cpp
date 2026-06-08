# include <vector>
# include <set>
# include <algorithm>
using namespace std;

int n, m;
int oilNum;
int sz;
vector<vector<int>> whichOil;
vector<vector<int>> visited;
vector<int> oilSize;
vector<pair<int, int>> dxdy = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(int x, int y, vector<vector<int>>& land){
    for (const auto& [dx, dy] : dxdy){
        int nx = x + dx, ny = y + dy;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m){
            continue;
        }
        if (land[nx][ny] == 1 && visited[nx][ny] == 0){
            visited[nx][ny] = 1;
            whichOil[nx][ny] = oilNum;
            dfs(nx, ny, land);
        }
    }
    ++sz;
}

int count(int y){
    int res = 0;
    set<int> oils;
    for (int x=0; x<n; x++){
        int oil = whichOil[x][y];
        if (oil != -1){
            oils.insert(oil);
        }
    }
    for (int oil : oils){
        res += oilSize[oil];
    }
    
    return res;
}

int solution(vector<vector<int>> land) {
    n = land.size();
    m = land[0].size();
    
    whichOil.assign(n, vector<int>(m, -1));
    visited.assign(n, vector<int>(m, 0));
    
    oilNum = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (land[i][j] == 1 && visited[i][j] == 0){
                sz = 0;
                visited[i][j] = 1;
                whichOil[i][j] = oilNum;
                dfs(i, j, land);
                oilSize.push_back(sz);
                ++oilNum;
            }
        }
    }
    
    int res = 0;
    for (int j=0; j<m; j++){
        res = max(res, count(j));
    }
    
    return res;
}