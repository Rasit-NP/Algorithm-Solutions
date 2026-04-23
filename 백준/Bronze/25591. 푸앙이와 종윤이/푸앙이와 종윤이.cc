# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int x, y;   cin >> x >> y;
    int a = 100-x, b = 100-y;
    int c = 100 - (a+b);
    int d = a*b;
    int q = d/100, r = d%100;

    cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << q << ' ' << r << '\n';
    cout << c+q << ' '<< r;
}