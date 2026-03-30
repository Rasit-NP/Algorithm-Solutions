# include <iostream>
using namespace std;


int main(void){
    int t, f, s, p, c;
    for (int i=0; i<2; i++){
        if (i)  cout << ' ';
        cin >> t >> f >> s >> p >> c;
        cout << 6*t + 3*f + 2*s + p + 2*c;
    }
}