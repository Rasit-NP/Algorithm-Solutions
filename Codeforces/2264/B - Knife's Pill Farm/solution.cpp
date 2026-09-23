# include <iostream>
# include <vector>
# include <queue>
# include <climits>
# include <algorithm>
using namespace std;
using llong = long long;
 
void solve();
 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
 
    int t;  cin >> t;
    while (t--){
        solve();
    }
}
 
void solve(){
    int n, m;   cin >> n >> m;
 
    vector<int> a(n, 0);
    for (llong i=0; i<n; ++i){
        cin >> a[i];
    }
 
    llong now = 0;
    llong res = LLONG_MIN;
    priority_queue<int> pq;
 
    for (int num : a){
        if (pq.size() == m-1){
            res = max(res, now + (llong)m * num);
        }
        now -= num;         pq.push(num);
        if (pq.size() == m){
            now += pq.top();
            pq.pop();
        }
    }
 
    cout << res << '\n';
}