# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n, m;   cin >> n >> m;
    int lim = 1;
    for (int i=0; i<n; ++i)
        lim *= 10;

    int bit = 0;

    for (int i=0; i<m; ++i){
        int v;  cin >> v;
        bit |= (1 << v);
    }

    int res = 0;

    for (int num=0; num<lim; ++num){
        int nowBit = 0;
        int v = num;

        for (int i=0; i<n; ++i){
            nowBit |= (1 << (v%10));
            v /= 10;
        }

        res += (bit&nowBit) == bit;
    }

    cout << res << '\n';
}