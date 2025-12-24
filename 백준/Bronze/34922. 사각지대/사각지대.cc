# include <iostream>
# include <cmath>
using namespace std;

int main(void){
    int w, h; cin >> w >> h;
    int r; cin >> r;
    cout << fixed;
    cout.precision(5);
    cout << (float) w*h - r*r*M_PI_4 << endl;
}