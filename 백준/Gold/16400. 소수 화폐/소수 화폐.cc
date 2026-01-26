# include <iostream>
# include <vector>
using namespace std;


int main(void){
    vector<int> primes;
    vector<bool> table(40001, true);
    table[0] = false, table[1] = false;
    for (int i=2; i<=40000; i++){
        if (table[i]){
            primes.push_back(i);
            for (int x=i; x<=40000; x+= i){
                table[x] = false;
            }
        }
    }

    int n;  cin >> n;
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for (int i=primes.size()-1; i>=0; i--){
        int prime = primes[i];
        if (prime > n)  continue;
        for (int x=prime; x<=n; x++){
            dp[x] += dp[x-prime];
            dp[x] %= 123456789;
        }
    }
    cout << dp[n] << endl;
}