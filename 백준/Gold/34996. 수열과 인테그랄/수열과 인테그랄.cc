# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;  cin >> n;
    double ans = n*n + n - 1;
    cout << ans << '\n';
    for (int i=-1; i>=-n; i--){
        if (i != -1)    cout << ' ';
        cout << i;
    }
    cout << " 0";
    for (int i=n; i>=1; i--){
        cout << ' ' << i;
    }
    cout << '\n';
}