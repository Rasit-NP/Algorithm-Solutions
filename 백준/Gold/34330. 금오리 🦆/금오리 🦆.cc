# include <iostream>
# include <vector>
# include <queue>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int cnt_caught = 0;
    long long r, l; cin >> r >> l;
    int n, m;       cin >> n >> m;
    vector<vector<long long>> flowers;
    vector<pair<long long, long long>> ducks;
    vector<int> startable;
    vector<vector<int>> edges_flower(n, vector<int>(0));
    vector<vector<int>> edges_duck(n, vector<int>(0));
    vector<bool> visited_flower(n, false);
    vector<bool> visited_duck(m, false);

    for (int i=0; i<n; i++){
        long long x, y, r_f;  cin >> x >> y >> r_f;
        flowers.push_back({x, y, r_f});
        long long dist = x*x + y*y;
        if (r_f>r){
            startable.push_back(i);
        }
        else if (dist >= (r-r_f)*(r-r_f) ){
            startable.push_back(i);
        }
    }
    for (int i=0; i<m; i++){
        long long x, y;     cin >> x >> y;
        ducks.push_back({x, y});
        if (x*x + y*y >= (r-l)*(r-l)){
            cnt_caught++;
            visited_duck[i] = true;
        }
    }

    if (l >= r){
        cout << m << '\n';
        return 0;
    }

    // 이동 가능, 포획 가능 경로 생성
    for (int i=0; i<n; i++){
        long long x1=flowers[i][0], y1 = flowers[i][1], r1 = flowers[i][2];
        for (int j=i+1; j<n; j++){
            long long x2=flowers[j][0], y2 = flowers[j][1], r2 = flowers[j][2];
            long long dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
            if (dist <= (r1+r2)*(r1+r2)){
                edges_flower[i].push_back(j);
                edges_flower[j].push_back(i);
            }
        }
        for (int j=0; j<m; j++){
            long long x2 = ducks[j].first, y2 = ducks[j].second;
            long long dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
            if (dist <= (l+r1)*(l+r1)){
                edges_duck[i].push_back(j);
            }
        }
    }

    queue<int> q;
    for (int idx_flower : startable){
        q.push(idx_flower);
        visited_flower[idx_flower] = true;
    }

    // BFS
    while (q.size()){
        int x = q.front();      q.pop();
        for (int nx : edges_flower[x]){
            if (!visited_flower[nx]){
                q.push(nx);
                visited_flower[nx] = true;
            }
        }
        for (int duck : edges_duck[x]){
            if (!visited_duck[duck]){
                cnt_caught++;
                visited_duck[duck] = true;
            }
        }
    }
    cout << cnt_caught << '\n';
}