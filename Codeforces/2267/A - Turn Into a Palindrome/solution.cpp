# include <iostream>
# include <string>
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
    int n;  char c; string s;
    cin >> n >> c >> s;
 
    int res = 0;
 
    for (int i=0, lim=n/2; i<lim; ++i){
        if (s[i] == s[n-i-1])
            continue;
        else if (s[i] == c || s[n-i-1] == c)
            ++res;
        else {
            res += 2;
        }
    }
 
    cout << res << '\n';
}