# include <iostream>
using namespace std;
using llong = long long;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    llong a;  cin >> a;
    llong b, c;

    if (a&1){
        b = (a*a - 1) >> 1;
        c = b + 1;
    }
    else {
        b = (a*a - 4) >> 2;
        c = b + 2;
    }

    cout << b << ' ' << c << ' ' << '\n';
}