# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;
    while (t--){
        int g, c, e;    cin >> g >> c >> e;

        if (c >= e){
            cout << "0\n";
            continue;
        }

        cout << (e-c)*(2*g-1) << '\n';
    }
}