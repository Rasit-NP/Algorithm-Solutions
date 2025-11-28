# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
using namespace std;

int days[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

bool check(int y) {
	if (!(y % 400))	return true;
	if (!(y % 100)) return false;
	if (!(y % 4))	return true;
	return false;
}

int day(int y, int m, int d) {
	int res = 0;
	for (int year = 1900; year < y; year++) {
		res += check(year) ? 366 : 365;
	}
	if (m > 2) {
		res += check(y) ? days[m] + 1 : days[m];
	}
	else {
		res += days[m];
	}
	res += d;
	return res;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int y, m, d, day1, day2, t, n;
	int q, c, v;
	cin >> y >> m >> d;
	day1 = day(y, m, d);
	cin >> y >> m >> d;
	day2 = day(y, m, d);
	cin >> t >> n;
	vector<pair<int, int>> options;
	vector<int> dp(t + 1);
	for (int i = 0; i < n; i++) {
		cin >> q >> c >> v;
		if (q == 3)
			v *= 30;
		options.push_back(make_pair(c, v));
	}
	sort(options.begin(), options.end());

	for (pair<int, int>option : options) {
		int cost = option.first, value = option.second;
		for (int w = t; w >= cost; w--) {
			if (dp[w] < dp[w - cost] + value) {
				dp[w] = dp[w - cost] + value;
			}
		}
	}
	cout << abs(dp[t] + (day1 - day2)) << endl;
}