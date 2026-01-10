# include <iostream>
using namespace std;

int main(void){
    int n;    cin >> n;
    long long ans = 1;
    for (int i=1; i<=n; i++){
        ans *= i;
    }
    cout << ans;
}