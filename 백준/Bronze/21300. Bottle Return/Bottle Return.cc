# include <iostream>
using namespace std;

int main(void){
    int ans = 0;
    int n;
    while(cin >> n){
        ans += n*5;
    }
    cout << ans;
}