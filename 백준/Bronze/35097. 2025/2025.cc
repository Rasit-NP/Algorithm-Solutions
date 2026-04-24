# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;
    while (true){
        cin >> n;
        if (n == 0){
            break;
        }
        int ans = 0;
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                ans += i*j;
            }
        }
        cout << ans << '\n';
    }
}