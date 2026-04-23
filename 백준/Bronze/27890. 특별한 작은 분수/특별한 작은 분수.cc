# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int x, n;   cin >> x >> n;
    for (int i=1; i<=n; i++){
        if (x&1){
            x = (x << 1)^6;
        }
        else {
            x = (x/2)^6;
        }
    }
    cout << x;
}