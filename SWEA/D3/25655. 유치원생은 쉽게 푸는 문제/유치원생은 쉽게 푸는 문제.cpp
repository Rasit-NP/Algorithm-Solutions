# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;
    while (t--){
        int x;  cin >> x;

        if (x == 1){
            cout << 0 << '\n';
            continue;
        }

        if (x&1){
            cout << 4;
        }
        for (int i=0; i<x/2; i++){
            cout << 8;
        }
        cout << '\n';
    }
}