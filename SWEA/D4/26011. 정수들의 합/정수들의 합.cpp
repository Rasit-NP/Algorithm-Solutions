# include <iostream>
# include <cmath>
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

long long get(int x, int n){
    if (x > n){
        int s = x - n;
        return n - s + 1;
    }
    else {
        return x - 1;
    }
}

void solve(){
    int n, k;   cin >> n >> k;

    k = abs(k);

    long long res = 0;

    for (int cd=2; cd<=2*n-k; ++cd){
        long long local = 0;
        int ab = k + cd;

        local = get(ab, n) * get(cd, n);
        res += local;
    }

    cout << res << '\n';
}