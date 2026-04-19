# include <iostream>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int a, b, c, d; cin >> a >> b >> c >> d;

    cout << min(b+c, a+d);
}