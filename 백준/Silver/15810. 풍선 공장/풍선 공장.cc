# include <iostream>
# include <vector>
# include <queue>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n, m;   cin >> n >> m;
    priority_queue<pair<long long, int>> times;

    for (int i=0; i<n; i++){
        int a;  cin >> a;
        times.push({-a, -a});
    }

    long long now_time;

    for (int cnt=0; cnt<m; cnt++){
        now_time = - times.top().first;
        int a = - times.top().second;
        times.pop();
        times.push({-now_time-a, -a});
    }
    cout << now_time << '\n';
}