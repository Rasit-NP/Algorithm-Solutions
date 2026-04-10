# include <iostream>
# include <algorithm>
using namespace std;

int main(void){
    int a, b, c, d;    cin >> a >> b >> c >> d;
    
    if (max(a+b, c) <= d)
        cout << "~.~";
    else if (min(a+b, c) > d)
        cout << "T.T";
    else if (a+b <= d)
        cout << "Shuttle";
    else
        cout << "Walk";
}