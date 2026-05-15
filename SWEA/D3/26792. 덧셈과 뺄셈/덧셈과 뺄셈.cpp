# include <iostream>
using namespace std;

void solve(){
    int x, y;   cin >> x >> y;
    cout << (x+y)/2 << ' ' << (x-y)/2 << '\n';
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;
    while (t--){
        solve();
    }
}