# include <iostream>
# include <vector>
using namespace std;
 
void solve(){
    int n;  cin >> n;
    vector<int> a(n, 0), b(n, 0);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    long long cnt = 0;
    bool res = true;
    for (int i=0; i<n; i++){
        cin >> b[i];
        cnt += (b[i] - a[i]);
        if (cnt < 0){
            res = false;
        }
    }
    
    cout << (res ? "YES" : "NO") << '\n';
}
 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
 
    int t;  cin >> t;
    while (t--){
        solve();
    }
}