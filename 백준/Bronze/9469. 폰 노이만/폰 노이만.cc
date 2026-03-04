# include <iostream>
using namespace std;

int main(void){
    int t;  cin >> t;
    while (t--){
        int n;  cin >> n;
        long double d, a, b, f; cin >> d >> a >> b >> f;

        cout << n << ' ';
        cout.precision(5);
        cout << fixed << d*f/(a+b) << '\n';
    }
}