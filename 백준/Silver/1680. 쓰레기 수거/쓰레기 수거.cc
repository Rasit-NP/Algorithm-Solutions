# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cin.tie(NULL);

    int t;
    cin >> t;

    for (int tc=1; tc<=t; tc++){
        int w, n;
        cin >> w >> n;
        vector<pair<int, int>> trash(n, {0, 0});
        for (int i=0; i<n; i++){
            cin >> trash[i].first >> trash[i].second;
        }
        int ans = 0;
        int now = 0;
        int pos = 0;
        for (int i=0; i<n; i++){
            if (now>=w) {
                ans += pos*2;
                now = 0;
            }
            ans += trash[i].first - pos;
            pos = trash[i].first;
            if (now + trash[i].second > w){
                ans += pos*2;
                now = 0;
            }
            now += trash[i].second;
        }
        ans += pos;
        cout << ans << endl;
    }
}
