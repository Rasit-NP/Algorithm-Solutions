# include <iostream>
# include <vector>
# include <queue>
using namespace std;

int n;
int MAX;
vector<pair<int, int>> positions;
vector<vector<pair<int, int>>> delta(3, vector<pair<int, int>>(0));
vector<vector<vector<pair<int, int>>>> visited(3, vector<vector<pair<int, int>>>(0));

void create_dxdy(){
    vector<pair<int, int>> delta_bishop = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    vector<pair<int, int>> delta_rook = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    delta[0] = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};
    for (int length=1; length<n; length++){
        for (pair<int, int> dxdy : delta_bishop){
            int dx = dxdy.first, dy = dxdy.second;
            delta[1].push_back({dx*length, dy*length});
        }
        for (pair<int, int> dxdy : delta_rook){
            int dx = dxdy.first, dy = dxdy.second;
            delta[2].push_back({dx*length, dy*length});
        }
    }
}

bool compare(pair<int, int> pairA, pair<int, int> pairB, pair<int, int> plus){
    int a_first = pairA.first, a_second = pairA.second;
    int b_first = pairB.first + plus.first, b_second = pairB.second + plus.second;

    if (a_first > b_first){
        return true;
    }
    else if (a_first == b_first && a_second > b_second){
        return true;
    }
    else {
        return false;
    }
}

void init(){
    cin >> n;
    MAX = n*n;
    positions.assign(MAX+1, {0, 0});
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            int value;  cin >> value;
            positions[value] = {i, j};
        }
    }
    int x1 = positions[1].first, y1 = positions[1].second;
    for (int i=0; i<3; i++){
        visited[i].assign(n, vector<pair<int, int>>(n, {1<<30, 1<<30}));
        visited[i][x1][y1] = {0, 0};
    }
    create_dxdy();
}

void move(int start, int end){

    int start_x = positions[start].first, start_y = positions[start].second;
    int end_x = positions[end].first, end_y = positions[end].second;

    vector<vector<pair<int, int>>> spent_time(3, vector<pair<int, int>>(3, {1<<30, 1<<30}));    // spent_time[start_state][end_state]

    for (int start_state=0; start_state<3; start_state++){
        queue<vector<int>> q;
        vector<vector<vector<pair<int, int>>>> local_visited(3, vector<vector<pair<int, int>>>(0));
        for (int state=0; state<3; state++){
            local_visited[state].assign(n, vector<pair<int, int>>(n, {1<<30, 1<<30}));
        }
        local_visited[start_state][start_x][start_y] = {0, 0};
        q.push({start_state, start_x, start_y});
        int check = 0;
        while (q.size()){
            int now_state = q.front()[0], x = q.front()[1], y = q.front()[2];
            q.pop();

            // 현재 말 이동
            for (pair<int, int> dxdy : delta[now_state]){
                int nx = x + dxdy.first, ny = y + dxdy.second;
                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;
                if (compare(local_visited[now_state][nx][ny], local_visited[now_state][x][y], {1, 0})){
                    local_visited[now_state][nx][ny] = local_visited[now_state][x][y];
                    local_visited[now_state][nx][ny].first++;
                    if (nx == end_x && ny == end_y){
                        if (check ^ (1<<now_state)){
                            check += 1<<now_state;
                        }
                        if (check == 7){
                            break;
                        }
                        continue;
                    }
                    else {
                        q.push({now_state, nx, ny});
                    }
                }
            }

            // 말 변경
            for (int new_state=0; new_state<3; new_state++){
                if (new_state == now_state)
                    continue;
                if (compare(local_visited[new_state][x][y], local_visited[now_state][x][y], {1, 1})){
                    local_visited[new_state][x][y] = local_visited[now_state][x][y];
                    local_visited[new_state][x][y].first++;
                    local_visited[new_state][x][y].second++;
                    q.push({new_state, x, y});
                }
            }
        }
        for (int end_state=0; end_state<3; end_state++){
            spent_time[start_state][end_state] = local_visited[end_state][end_x][end_y];
        }
    }

    for (int start_state=0; start_state<3; start_state++){
        for (int end_state=0; end_state<3; end_state++){
            if (spent_time[start_state][end_state].first == 1<<30)  continue;
            if (compare(visited[end_state][end_x][end_y], visited[start_state][start_x][start_y], spent_time[start_state][end_state])){
                visited[end_state][end_x][end_y] = {visited[start_state][start_x][start_y].first + spent_time[start_state][end_state].first, visited[start_state][start_x][start_y].second + spent_time[start_state][end_state].second};
            }
        }
    }
}

int main(void){
    init();
    
    for (int now=1; now<MAX; now++){
        move(now, now+1);
    }
    
    int res_time=1<<30, res_changed=1<<30;
    for (int state=0; state<3; state++){
        pair<int, int> res = visited[state][positions[MAX].first][positions[MAX].second];
        if (compare({res_time, res_changed}, res, {0, 0})){
            res_time = res.first;
            res_changed = res.second;
        }
    }
    cout << res_time << ' ' << res_changed;
}