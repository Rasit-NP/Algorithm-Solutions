# include <iostream>
# include <algorithm>
# include <vector>
# include <queue>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, x, m, mini=1<<30, ans = 0;
	cin >> t >> x >> m;
	for (int i = 0; i < m; i++) {
		int d, s, r;
		cin >> d >> s;
		r = (d - 1) / s;
		mini = min(mini, r);
	}
	if (mini == 0) {
		cout << 0 << '\n';
		return 0;
	}
	if (mini <= t) {
		ans += mini;
		ans += (t - mini) / 2;
	}
	else {
		ans += t;
	}
	cout << ans * x << '\n';
}