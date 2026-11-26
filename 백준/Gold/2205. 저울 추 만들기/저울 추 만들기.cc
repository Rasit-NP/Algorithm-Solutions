# include <iostream>
# include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;

    vector<int> res(n+1, -1);

    for (int i=n; i>0; --i){
        if (res[i] == -1){
            int val = 1;
            while (val <= i){
                val <<= 1;
            }

            res[i] = val-i;
            res[val-i] = i;
        }
    }

    for (int i=1; i<=n; ++i){
        cout << res[i] << '\n';
    }
}