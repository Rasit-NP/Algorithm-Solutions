# include <iostream>
# include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> dp(101, 0);
    dp[1] = 2;
    for (int i=1; i<100; i++){
        dp[i+1] = dp[i] + (i-(i/3)) + 1;
    }
    int n; cin >> n;
    cout << dp[n] << '\n';
}