# include <iostream>
# include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;

    vector<int> res(1'000'001, -1);
    res[0] = 0;

    for (int i=1; i<=1'000; ++i){
        res[i*i] = 1;
    }

    for (int i=2; i<=1'000'000; ++i){
        if (res[i] != -1) continue;

        res[i] = 0;
        for (int j=1; j*j<=i; ++j){
            if (res[i - j*j] == 0){
                res[i] = 1;
                break;
            }
        }
    }

    while (t--){
        int n;  cin >> n;

        cout << (res[n] ? "koosaga" : "cubelover") << '\n';
    }
}