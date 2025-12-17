# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b; cin >> a >> b;
    int l=0, r=0;
    while (a != 1 && b != 1){
        if (a > b){
            a -= b;
            l++;
        }
        else {
            b -= a;
            r++;
        }
    }
    if (a != 1){
        l += a-1;
    }
    else if (b != 1){
        r += b-1;
    }
    cout << l << ' ' << r << '\n';
}