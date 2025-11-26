# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main(void) {
	int n, m, i;
	cin >> n >> m;
	vector<pair<int, int>> points;
	for (i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		points.push_back(make_pair(x, y));
	}
	long long ans = 0;
	for (i = 0; i < m; i++) {
		long long x, y, maximum=0;
		cin >> x >> y;
		for (pair<int, int> point : points) {
			long long dist = (point.first - x)*(point.first - x) + (point.second - y)*(point.second - y);
			maximum = max(maximum, dist);
		}
		ans = max(maximum, ans);
	}
	cout << ans << '\n';
}