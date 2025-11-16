# include <iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i=0, ans=0;
    cin >> n;
    for (; i<n; i++){
        char x;
        cin >> x;
        ans += x-'0';
    }
    cout << ans;
}