# include <iostream>
# include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;
    for (int tc=1; tc<=t; tc++){
        int maxi = -1;
        for (int i=0; i<10; i++){
            int x;  cin >> x;
            maxi = max(maxi, x);
        }
        cout << "#" << tc << ' ' << maxi << '\n';
    }
}