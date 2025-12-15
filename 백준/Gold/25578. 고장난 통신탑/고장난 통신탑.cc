# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>
# define MAX (int)sqrt(20000000)
using namespace std;

vector<int> primes;
vector<bool> check(MAX, true);

int find(int a, int b){
    int temp;
    while (a%b != 0){
        temp = a;
        a = b;
        b = temp % b;
    }
    return b;
}

int cal(int a){
    for (int prime : primes){
        if (a%prime == 0)
            return prime;
    }
    return a;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    check[0] = false; check[1] = false;
    for (int i=2; i<MAX; i++){
        if (check[i])   primes.push_back(i);
        for (int k = 2*i; k<MAX; k += i){
            check[k] = false;
        }
    }

    int t; cin >> t;
    for (int tc=1; tc<=t; tc++){
        int a, b; cin >> a >> b;

        if (max(a, b) % min(a, b) == 0){
            cout << a << ' ' << b << '\n';
            continue;
        }
        if ((a&1) && (b&1)){
            cout << a << " 1 " << b << '\n';
            continue;
        }
        int cd = find(max(a, b), min(a, b));
        if (cd != 1){
            cout << a << ' ' << cal(cd) << ' ' << b << '\n';
            continue;
        }
        else {
            cout << a << ' ' << (long)a*b/cd << ' ' << b << '\n';
        }
    }
}