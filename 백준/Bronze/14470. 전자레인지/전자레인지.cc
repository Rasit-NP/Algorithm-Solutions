# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int a, b, c, d, e;  cin >> a >> b >> c >> d >> e;

    bool isFrozen = (a < 0);

    int ans = 0;
    while (a < b){
        if (a < 0){
            ans += c;
            ++a;
        }
        else if (a == 0 && isFrozen){
            ans += d;
            isFrozen = false;
        }
        else{
            ans += e;
            ++a;
        }
    }

    cout << ans;
}