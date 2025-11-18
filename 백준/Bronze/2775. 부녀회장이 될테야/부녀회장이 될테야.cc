# include <iostream>
# include <vector>
using namespace std;

vector<vector<int>> memo(15, vector<int>(15));
int cal(int k, int n) {
	if (memo[k][n])
		return memo[k][n];
	if (k == 0) {
		memo[k][n] = n;
		return n;
	}
	else {
		int res = 0;
		for (int i = 1; i <= n; i++) {
			res += cal(k - 1, i);
		}
		memo[k][n] = res;
		return res;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, tc=0;
	cin >> t;
	for (; tc < t; tc++) {
		int k, n;
		cin >> k >> n;
		int res = cal(k, n);
		cout << res << '\n';
	}
}