# include <iostream>
# include <vector>
# include <queue>
using namespace std;

int k, n1, m1, n2, m2;
int a, b;
int r1, c1, r2, c2;
int ans = 0;
vector<int> n;
vector<int> m;
vector<int> r;
vector<int> c;
vector<vector<vector<int>>> cannot_time(2, vector<vector<int>>(0));
vector<vector<vector<int>>> visited(2, vector<vector<int>>(0));
priority_queue<vector<int>> q;

void go(int num, int x, int y, int n, int m){
    while (true){
        int nx, ny;
        nx = x;
        if (x&1){
            ny = y-1;
        }
        else{
            ny = y+1;
        }
        if (ny<0 || ny>=m){
            ny = y;
            nx = x+1;
        }
        if (nx>=n){
            nx = 0, ny=0;
        }
        if (cannot_time[num][nx][ny] == 1)  break;
        cannot_time[num][nx][ny] = cannot_time[num][x][y] + 1;
        x = nx, y = ny;
    }
}

void init(){
    cin >> k >> n1 >> m1 >> n2 >> m2;
    cannot_time[0].assign(n1, vector<int>(m1, 1<<30));
    cannot_time[1].assign(n2, vector<int>(m2, 1<<30));
    visited[0].assign(n1, vector<int>(m1, 1<<30));
    visited[1].assign(n2, vector<int>(m2, 1<<30));
    cin >> a >> b;
    cin >> r1 >> c1;
    cin >> r2 >> c2;
    n.push_back(n1); n.push_back(n2);
    m.push_back(m1); m.push_back(m2);
    r.push_back(r1); r.push_back(r2);
    c.push_back(c1); c.push_back(c2);
    for (int i=0; i<k; i++){
        int d, dr, dc;
        cin >> d >> dr >> dc;
        cannot_time[d-1][dr][dc] = 1;
    }

    for (int dim=0; dim<2; dim++){
        for (int x=0; x<n[dim]; x++){
            for (int y=0; y<m[dim]; y++){
                if (cannot_time[dim][x][y] == 1){
                    go(dim, x, y, n[dim], m[dim]);
                }
            }
        }
    }
}

int main(void){
    init();
    
    visited[0][0][0] = 0;
    q.push({0, 0, 0, 0});
    vector<pair<int, int>> dxdy = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    while (q.size()){
        vector<int> now = q.top();
        q.pop();
        int t = -now[0], dim = now[1], x = now[2], y = now[3];
        if (t>visited[dim][x][y])   continue;
        int nx, ny, nt;
        if (dim == 1 && x == n2-1 && y == m2-1){
            ans = t;
            break;
        }
        for (pair<int, int> dp : dxdy){
            int dx = dp.first, dy = dp.second;
            nt = t+1;
            nx = x+dx, ny = y+dy;
            if (nx<0 || ny<0 || nx>=n[dim] || ny>=m[dim]){
                continue;
            }
            if (nt < cannot_time[dim][nx][ny]-1 && nt < visited[dim][nx][ny]){
                visited[dim][nx][ny] = nt;
                q.push({-nt, dim, nx, ny});
            }
        }
        if ((x >= r[dim] && x < r[dim] + a) && (y >= c[dim] && y < c[dim] + b)){
            nt = t+3;
            nx = r[!dim] + (x-r[dim]);
            ny = c[!dim] + (y-c[dim]);
            if (nt < cannot_time[!dim][nx][ny]-1 && nt < visited[!dim][nx][ny]){
                visited[!dim][nx][ny] = nt;
                q.push({-nt, !dim, nx, ny});
            }
        }
    }
    if (ans){
        cout << ans << endl;
    }
    else{
        cout << "hing..." << endl;
    }
}