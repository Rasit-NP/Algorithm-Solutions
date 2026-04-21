# include <iostream>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int a, b;   cin >> a >> b;
    int c = a+b, d = a-b;

    cout << max(c, d) << '\n' << min(c, d);
}