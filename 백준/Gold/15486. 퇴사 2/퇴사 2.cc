# include <iostream>
# include <vector>
# include <utility>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, i = 0;
	cin >> n;
	vector<vector<int>> dp(n+55, vector<int>(51));
	for (i = 0; i < n; i++) {
		int t, p;
		cin >> t >> p;
		int np = dp[i][0] + p;
		if (dp[i][t] < np) {
			for (int j = 0; j <= t; j++) {
				dp[i + j][t - j] = np;
			}
		}
		dp[i + 1][0] = dp[i][0] > dp[i + 1][0] ? dp[i][0] : dp[i + 1][0];
	}
	int maximum = dp[n - 1][1] > dp[n - 1][0] ? dp[n - 1][1] : dp[n - 1][0];
	cout << maximum << '\n';
}