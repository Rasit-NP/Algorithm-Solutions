# include <iostream>
# include <vector>
# include <algorithm>
# define MAX 2000*2000
using namespace std;

vector<pair<int, int>> tasks;
vector<vector<int>> dp;

int dist(int i, int j){
    return abs(tasks[i].first-tasks[j].first) + abs(tasks[i].second-tasks[j].second);
}

void func(int x, int y){
    if (x == 0 && y == 1){
        return;
    }
    if (x > y){
        if (x-1 > y){
            func(x-1, y);
        }
        else if (y == x-1){
            int target;
            for (int i=0; i<x; i++){
                if (dp[i][y] + dist(i, x) == dp[x][y]){
                    target = i;
                    break;
                }
            }
            func(target, y);
        }
        cout << 1 << '\n';
    }
    else if (x < y){
        if (x < y-1){
            func(x, y-1);
        }
        else if (x == y-1) {
            int target;
            for (int i=0; i<y; i++){
                if (dp[x][i] + dist(i, y) == dp[x][y]){
                    target = i;
                    break;
                }
            }
            func(x, target);
        }
        cout << 2 << '\n';
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n, w;   cin >> n >> w;
    tasks.push_back({1, 1});
    tasks.push_back({n, n});
    for (int i=0; i<w; i++){
        pair<int, int> task = {0, 0};
        cin >> task.first >> task.second;
        tasks.push_back(task);
    }

    dp.assign(w+2, vector<int>(w+2, MAX));
    dp[0][1] = 0;

    for (int i=2; i<w+2; i++){
        for (int j=0; j<i-1; j++){
            if (j != 1){
                dp[i][i-1] = min(dp[i][i-1], dp[j][i-1] + dist(j, i));
                dp[j][i] = min(dp[j][i], dp[j][i-1] + dist(i-1, i));
            }
            if (j != 0){
                dp[i-1][i] = min(dp[i-1][i], dp[i-1][j] + dist(j, i));
                dp[i][j] = min(dp[i][j], dp[i-1][j] + dist(i-1, i));
            }
        }
    }

    int x, y, ans = MAX;
    for (int i=0; i<w+2; i++){
        if (dp[w+1][i] < ans){
            ans = dp[w+1][i];
            x = w+1, y = i;
        }
        if (dp[i][w+1] < ans){
            ans = dp[i][w+1];
            x = i, y = w+1;
        }
    }

    cout << ans << '\n';
    func(x, y);
}