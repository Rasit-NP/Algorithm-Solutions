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
    vector<int> wrongPos;
 
    for (int i=0; i<n; ++i){
        cin >> nums[i];
        if (nums[i] != i+1){
            wrongPos.emplace_back(i);
        }
    }
 
 
    int m = wrongPos.size();
    for (int i=0, j=m-1; i<=j; ++i, --j){
        int x = wrongPos[i];
        int y = wrongPos[j];
 
        int xv = nums[x] - 1;
        int yv = nums[y] - 1;
 
        if (x != yv || y != xv){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}