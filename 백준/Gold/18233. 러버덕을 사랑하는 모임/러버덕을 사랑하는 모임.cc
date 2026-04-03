# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int countMember(int state){
    int res = 0;
    while (state){
        res += (state & 1);
        state >>= 1;
    }
    return res;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n, p, e;    cin >> n >> p >> e;
    int mini, maxi, ansState = -1;
    vector<int> low(n), high(n);
    vector<int> ans(n);
    for (int i=0; i<n; i++){
        cin >> low[i] >> high[i];
    }
    for (int state = 0; state<(1<<n); state++){
        mini = 0, maxi = 0;
        if (countMember(state) != p){
            continue;
        }
        for (int i=0; i<n; i++){
            if (state & (1 << i)){
                mini += low[i];
                maxi += high[i];
            }
        }
        if (e>= mini && e<= maxi){
            ansState = state;
            for (int i=0; i<n; i++){
                ans[i] = high[i] * ((state >> i) & 1);
            }
            break;
        }
    }
    if (ansState == -1){
        cout << -1;
        return 0;
    }
    for (int i=0; i<n && maxi > e; i++){
        if (ans[i] == 0){
            continue;
        }
        int diff = maxi - e;
        int localDiff = high[i] - low[i];

        ans[i] -= min(diff, localDiff);
        maxi -= min(diff, localDiff);
    }

    for (int i=0; i<n; i++){
        cout << ans[i] << " \n"[i == n-1];
    }
}