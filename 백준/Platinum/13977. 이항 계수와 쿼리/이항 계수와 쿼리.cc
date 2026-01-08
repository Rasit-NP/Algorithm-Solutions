# include <iostream>
# include <vector>
# define MAX 1000000007
using namespace std;

vector<int> factorial(4000001, 1);

void init(void){
    for (int i=2; i<=4000000; i++){
        long long num = (long long)factorial[i-1] * i;
        num %= MAX;
        factorial[i] = (int) num;
    }
}

int calculate(int n, int k){
    long long ans = factorial[n];
    long long k_f = factorial[k], nk_f = factorial[n-k];
    long long mid = (k_f * nk_f) % MAX;

    long long res = 1;
    long long bin = mid;
    for (int num = MAX-2; num > 0; num = num >> 1, bin = (bin * bin) % MAX){
        if (num & 1){
            res = (res*bin) % MAX;
        }
    }
    ans = (ans * res) % MAX;
    return (int) ans;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    init();
    int m;  cin >> m;
    int n, k;
    for (int test=1; test<=m; test++){
        cin >> n >> k;
        cout << calculate(n, k) << '\n';
    }
}