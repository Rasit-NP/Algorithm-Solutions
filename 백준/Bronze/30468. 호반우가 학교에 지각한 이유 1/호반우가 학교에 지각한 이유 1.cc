# include <iostream>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int s, d, i, l, n;  cin >> s >> d >> i >> l >> n;

    cout << max(4*n - (s+d+i+l), 0);
}