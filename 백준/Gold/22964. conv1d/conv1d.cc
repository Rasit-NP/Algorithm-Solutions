# include <iostream>
# define MAX 998244353
using namespace std;

long long pow(long long x, long long a){
    long long res = 1;
    long long bias = x;
    for (; a; a >>= 1, bias = (bias*bias)%MAX){
        if (a&1){
            res *= bias;
            res %= MAX;
        }
    }
    return res;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    long long n, k, x;    cin >> n >> k >> x;

    long long res = 0;
    res += x * (x+1) / 2;
    res %= MAX;
    res = res * res;
    res %= MAX;

    res *= pow(x, 2*k-2);
    res %= MAX;

    res *= k;
    res %= MAX;

    res *= pow(x, n-k);
    res %= MAX;

    for (int i=0; i<n-k+1; i++){
        if (i)  cout << ' ';
        cout << res;
    }
}