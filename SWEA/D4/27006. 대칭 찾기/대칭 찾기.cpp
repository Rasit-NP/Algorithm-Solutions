# include <iostream>
# include <vector>
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
    int res = 0;
    vector<vector<char>> table(n, vector<char>(n));

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> table[i][j];
        }
    }

    for (int diff=0; diff<n; ++diff){
        int a = 0, b = a+diff;
        bool chk1 = true;
        bool chk2 = true;
        for (int i=0; i<n; i++){
            for (int j=i; j<n; j++){                
                if (table[(i-a+n)%n][(j-b+n)%n] != table[(j-a+n)%n][(i-b+n)%n])
                    chk1 = false;
                
                if (table[(i-b+n)%n][(j-a+n)%n] != table[(j-b+n)%n][(i-a+n)%n])
                    chk2 = false;
                
                if (!chk1 && !chk2)
                    break;
            }
            if (!chk1 && !chk2)
                break;
        }
        if (chk1)
            res += n-b;
        if (a != b && chk2)
            res += n-b;
    }

    cout << res << '\n';
}