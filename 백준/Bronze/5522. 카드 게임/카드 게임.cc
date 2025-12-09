# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int x, ans=0;
    while (cin >> x){
        ans += x;
    }
    cout << ans << '\n';
}