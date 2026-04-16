# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int a, b;   cin >> a >> b;
    int num = a+b;
    int ans = 0;
    while (num){
        ++ans;
        num /= 10;
    }

    cout << ans;
}