# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int x, l, r;    cin >> x >> l >> r;
    if (x < l){
        cout << l;
    }
    else if (x > r){
        cout << r;
    }
    else {
        cout << x;
    }
}