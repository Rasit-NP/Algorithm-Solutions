# include <iostream>
# include <cmath>
typedef long double ldouble;
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    ldouble a, b;   cin >> a >> b;
    ldouble m = (b-a)/400;


    cout.precision(5);
    cout << fixed << 1/(1+powl(10, m));
}