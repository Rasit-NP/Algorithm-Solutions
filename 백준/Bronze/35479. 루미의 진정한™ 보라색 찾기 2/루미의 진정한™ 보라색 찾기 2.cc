# include <iostream>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    double r, g, b;    cin >> r >> g >> b;
    double rp = r/255, gp = g/255, bp = b/255;
    double k = 1-max(rp, max(gp, bp)), c = (1-rp-k)/(1-k), m = (1-gp-k)/(1-k), y = (1-bp-k)/(1-k);

    if (k == 1){
        c = 0, m = 0, y = 0;
    }

    cout.precision(8);
    cout << fixed;
    cout << c << ' ' << m << ' ' << y << ' ' << k;
}