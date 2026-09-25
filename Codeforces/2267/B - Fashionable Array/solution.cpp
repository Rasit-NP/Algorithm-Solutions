# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
 
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
    int n;  cin >> n;
    vector<int> nums(n, 0);
    vector<int> cnt(101, 0);
    vector<int> res;
    res.reserve(n);
 
    for (int& num : nums){
        cin >> num;
        ++cnt[num];
    }
 
    while (res.size() < n){
        int val = 0;
        for (int i=100; i>0; --i){
            if (!cnt[i])
                continue;
 
            if (!val && cnt[i]){
                val = cnt[i];
                for (int k=0; k<cnt[i]; ++k){
                    res.emplace_back(i);
                }
                cnt[i] = 0;
            }
            else if (val && cnt[i]){
                for (int k=0; k<min(val, cnt[i]); ++k){
                    res.emplace_back(i);
                }
                cnt[i] -= min(val, cnt[i]);
            }
        }
    }
 
    for (int i=0; i<n; ++i){
        cout << res[i] << " \n"[i == n-1];
    }
}