# include <iostream>
# include <algorithm>
# include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, x, y, i, target;
    cin >> n >> m >> x >> y;
    priority_queue<int> pq;
    int h, my_s, s;
    cin >> h >> my_s;
    for (i=0; i<n-1; i++){
        cin >> h >> s;
        if (h<2024000000)   continue;
        else
            pq.push(max(0, s+(y-x)) + s);
    }
    if (m>pq.size()){
        cout << "YES\n" << 0;
        return 0;
    }
    for (i=0; i<m; i++) {
        target = pq.top();
        pq.pop();
    }
    if (target-my_s <= y)
            cout << "YES\n" << max(0, target-my_s);
    else    cout << "NO\n";
}