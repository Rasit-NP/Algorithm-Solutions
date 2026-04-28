# include <iostream>
# include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    long long n, k;   cin >> n >> k;
    int l = 1, r = n;
    int left = n;
    vector<int> ans;

    while (l<=r){
        if (left-1 <= k){
            ans.push_back(r--);
            k -= (left-1);
        }
        else {
            ans.push_back(l++);
        }
        left--;
    }

    if (k == 0){
        for (int i=0; i<n; ++i){
            cout << ans[i] << " \n"[i == n-1];
        }
    }
    else {
        cout << -1;
    }
}