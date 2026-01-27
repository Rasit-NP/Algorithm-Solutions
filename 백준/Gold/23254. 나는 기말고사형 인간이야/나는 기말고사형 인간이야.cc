# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n, m;   cin >> n >> m;
    vector<int> nowscore(m, 0), score(m, 0);
    priority_queue<pair<int, int>> q;
    for (int i=0; i<m; i++){
        cin >> nowscore[i];
    }
    for (int i=0; i<m; i++){
        cin >> score[i];
        q.push({min(100-nowscore[i], score[i]), i});
    }
    for (int i=0; i<24*n; i++){
        int dScore = q.top().first, idx = q.top().second;   q.pop();
        nowscore[idx] += dScore;
        q.push({min(100-nowscore[idx], score[idx]), idx});
    }
    int ans = 0;
    for (int res : nowscore){
        ans += res;
    }
    cout << ans << '\n';
}