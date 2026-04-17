# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int b;  cin >> b;
    int res = 5*b - 400;

    cout << res << '\n';
    if (res > 100)
        cout << -1;
    else if (res < 100)
        cout << 1;
    else
        cout << 0;
}