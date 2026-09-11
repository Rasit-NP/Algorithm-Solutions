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
    vector<int> nums(n+1, 0);
    nums[0] = nums[1] = 1;

    for (int i=2; i<=n; i++){
        vector<int> bans;
        bans.reserve(n);
        for (int k=1; k<=i/2; k++){
            int val = 2*nums[i-k] - nums[i-2*k];
            if (val > 0)
                bans.push_back(2*nums[i-k] - nums[i-2*k]);
        }
        sort(bans.begin(), bans.end());
        bans.erase(unique(bans.begin(), bans.end()), bans.end());
        int cand = 1;
        for (int ban : bans){
            if (ban == cand)
                ++cand;
            else
                break;
        }
        nums[i] = cand;
    }

    cout << nums[n] << endl;
}