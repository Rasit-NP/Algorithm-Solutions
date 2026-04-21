# include <iostream>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int a, b, c, d, e, f;   cin >> a >> b >> c >> d >> e >> f;
    cout << (a+b+c+d)-min(a, min(b, min(c, d))) + max(e, f);
}