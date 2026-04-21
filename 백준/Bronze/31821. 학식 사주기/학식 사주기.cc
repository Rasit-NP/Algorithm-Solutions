# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    int prices[11];
    for (int i=1; i<=n; i++){
        cin >> prices[i];
    }
    
    int m;  cin >> m;
    int ans = 0;
    for (int i=0; i<m; i++){
        int b;  cin >> b;
        ans += prices[b];
    }

    cout << ans;
}