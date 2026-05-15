# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

void solve(){
    int n;  cin >> n;

    vector<pair<int, int>> works;
    for (int i=0; i<n; i++){
        int d, t;   cin >> d >> t;
        works.emplace_back(t, d);
    }
    sort(works.begin(), works.end());

    int now = 0;
    int mini = 1000000001;
    for (const pair<int, int>& work : works){
        int t = work.first, d = work.second;
        now += d;
        mini = min(mini, t-now);
    }

    cout << mini << '\n';
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;
    while (t--){
        solve();
    }
}