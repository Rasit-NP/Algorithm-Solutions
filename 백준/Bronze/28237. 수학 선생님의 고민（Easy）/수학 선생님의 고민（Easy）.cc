# include <iostream>
# include <cmath>
# include <unordered_set>
using namespace std;

unordered_set<int> squares;

int inSqrt(int n){
    int res = 5*n*n + 10*n + 1;
    if (squares.find(res) != squares.end()){
        return round(sqrt(res));
    }
    else {
        return 0;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    for (int i=1; i<=15000; ++i){
        squares.insert(i*i);
    }

    int n;  cin >> n;
    int sq = inSqrt(n);
    if (!sq){
        cout << -1;
        return 0;
    }

    int a = -(n+1) + sq, b = -(n+1) - sq;

    for (int i=1; i<=n; i++){
        if (n%i){
            continue;
        }

        int am = 2*n/i, bm = 2*i;
        if (a%am == 0 && b%bm == 0){
            cout << i << ' ' << -a/am << ' ' << n/i << ' ' << -b/bm;
            return 0;
        }
    }
    cout << -1;
}