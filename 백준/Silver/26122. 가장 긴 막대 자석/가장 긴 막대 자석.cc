# include <iostream>
# include <string>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    
    int n;  cin >> n;
    string s;   cin >> s;

    int res = 0;
    int bef = 0;
    int now = 1;
    for (int i=1; i<n; ++i){
        if (s[i-1] == s[i]){
            ++now;
        }
        else {
            res = max(res, min(bef, now));
            bef = now;
            now = 1;
        }
    }
    
    res = max(res, min(bef, now));

    cout << 2 * res << '\n';
}