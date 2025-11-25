# include <iostream>
# include <vector>
using namespace std;

int main(void) {
	int n, ans = 0;
	cin >> n;

	vector<vector<long long>> dp(100, vector<long long>(10, 0));
	vector<vector<vector<int>>> dp2(10, vector<vector<int>>(101, vector<int>(1 << 10, 0)));
	for (int i = 0; i < 10; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i < 100; i++) {
		for (int j = 0; j < 10; j++) {
			if (j > 0 && j < 9)
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])%1000000000;
			else if (j == 0)
				dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1];
		}
	}
	for (int i = 1; i < 10; i++) {
		dp2[i][1][1 << i] = 1;
	}
	for (int t = 1; t < n; t++) {
		for (int x = 0; x < 10; x++) {
			for (int course = 1; course < (1 << 10) - 1; course++) {
				if (!(course&(1 << x)))	continue;
				if (x > 0) {
					dp2[x - 1][t + 1][course | (1 << (x - 1))] += dp2[x][t][course];
					dp2[x - 1][t + 1][course | (1 << (x - 1))] %= 1000000000;
				}
				if (x < 9) {
					dp2[x + 1][t + 1][course | (1 << (x + 1))] += dp2[x][t][course];
					dp2[x + 1][t + 1][course | (1 << (x + 1))] %= 1000000000;
				}
			}
		}
	}
	for (int t = 10; t <= n; t++) {
		for (int i = 0; i < 10; i++) {
			ans += (dp2[i][t][(1 << 10) - 1] * dp[n-t][i])%1000000000;
			ans %= 1000000000;
		}
	}
	cout << ans << '\n';
}