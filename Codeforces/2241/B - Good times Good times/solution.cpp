# include <iostream>
# include <vector>
# include <string>
using namespace std;
 
void solve(){
    int x;  cin >> x;
    int len = to_string(x).size();
 
    int res = 1;
    while (len--){
        res *= 10;
    }
    res += 1;
 
    cout << res << '\n';
}
 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
 
    int t;  cin >> t;
 
    while (t--){
        solve();
    }
}