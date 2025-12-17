# include <iostream>
# include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;

    int total = n*(n+1) / 2;
    if (total & 1){
        cout << "0\n";
        return 0;
    }
    total /= 2;
    vector<int> dp(total+1, 0);
    dp[0] += 1;
    for (int i=1; i<=n; i++){
        for (int j=total; j>=i; j--){
            dp[j] += dp[j-i];
        }
    }
    cout << dp[total] / 2 << '\n';
}