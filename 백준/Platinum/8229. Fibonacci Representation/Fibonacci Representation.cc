# include <iostream>
# include <vector>
# include <algorithm>
# include <unordered_map>
# include <cmath>
using namespace std;

vector<long long> fibonacci;
unordered_map<long long, int> memo;


void init(){
    long long a = 1, b = 2;
    while (a >= 0 && a < 750000000000000000){
        fibonacci.push_back(a);
        memo[a] = 1;
        long long temp = a+b;
        a = b;  b = temp;
    }
}

long long solve(long long n){
    n = llabs(n);
    if (memo.find(n) != memo.end()){
        return memo[n];
    }
    int idx = 0;
    while (fibonacci[idx] < n){
        idx++;
    }
    if (fibonacci[idx] == n){
        memo[n] = 1;
    }
    else {
        if (2*n == fibonacci[idx-1] + fibonacci[idx]){
            memo[n] = solve(fibonacci[idx]-n) + 1;
        }
        else {
            memo[n] = min(solve(n-fibonacci[idx-1]), solve(fibonacci[idx]-n)) + 1;
        }
    }
    return memo[n];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    init();
    
    int p;  cin >> p;
    for (int i=0; i<p; i++){
        long long k;    cin >> k;
        cout << solve(k) << '\n';
    }
}