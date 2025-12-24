# include <iostream>
# include <algorithm>
using namespace std;

int main(void){
    int a, t; cin >> a >> t;

    cout << max(0, 10+2*(25-a+t)) << endl;
}