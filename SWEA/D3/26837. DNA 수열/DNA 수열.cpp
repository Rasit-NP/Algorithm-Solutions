# include <iostream>
# include <string>
# include <utility>
# include <map>
using namespace std;
typedef pair<int, int> pii;

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
    int n;      cin >> n;
    string s;   cin >> s;

    int res = 0;
    pii now;
    map<pii, int> cnt;
    cnt[{0, 0}] = 1;

    for (char c : s){
        switch (c){
            case 'A':
                ++now.first;
                break;
            case 'T':
                --now.first;
                break;
            case 'C':
                ++now.second;
                break;
            case 'G':
                --now.second;
                break;
        }

        res += cnt[now]++;
    }

    cout << res << '\n';
}