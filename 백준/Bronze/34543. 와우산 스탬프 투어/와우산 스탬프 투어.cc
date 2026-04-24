# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n, w;   cin >> n >> w;
    int ans = 10*n;
    if (n>=3){
        ans += 20;
    }
    if (n==5){
        ans += 50;
    }
    if (w > 1000){
        ans -= 15;
    }

    cout << (ans >= 0 ? ans : 0);
}