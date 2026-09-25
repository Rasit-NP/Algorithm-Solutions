# include <iostream>
# include <vector>
# include <set>
# include <algorithm>
using namespace std;
 
set<int> primes;
 
void solve();
 
int gcd(int, int);
 
void getPrimes(){
    vector<int> primeChecker(300001, 1);
 
    primeChecker[0] = primeChecker[1] = 0;
 
    for (int i=2; i<=300000; ++i){
        if (primeChecker[i]){
            primes.insert(i);
            for (int j=2*i; j<=300000; j += i){
                primeChecker[j] = 0;
            }
        }
    }
}
 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
 
    getPrimes();
 
    int t;  cin >> t;
    while (t--){
        solve();
    }
}
 
void solve(){
    int n, x;   cin >> n >> x;
    vector<int> nums(n, 0);
 
    for (int& num : nums){
        cin >> num;
    }
    
    if (x == 1){
        cout << "0\n";
        return;
    
    }
 
    set<int> primeFactors;
 
    for (int prime : primes){
        if (x == 1)
            break;
        while (x % prime == 0){
            x /= prime;
            primeFactors.insert(prime);
        }
    }
 
    long long res = 0;
 
    for (int prime : primeFactors){
 
        long long now = 0;
        for (int num : nums){
            if (num % prime == 0){
                now += num;
            }
        }
        res = max(res, now);
    }
 
    cout << res << '\n';
}