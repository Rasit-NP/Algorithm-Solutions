# include <iostream>
# include <queue>
# include <vector>
# include <algorithm>
using namespace std;

int main(void) {
	int n, i;
	long long ans = 0;
	cin >> n;
	vector<int> a(n), b(n), c(n), d(n);
	vector<int> ab, cd;
	for (i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	for (i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ab.push_back(a[i] + b[j]);
			cd.push_back(c[i] + d[j]);
		}
	}
	a.clear(); b.clear(); c.clear(); d.clear();
	sort(cd.begin(), cd.end());
	for (int v : ab) {
		int target = -v;
		int l = -1, r = n * n - 1;
		int small = -1, large = -1;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			if (cd[mid] >= target) {
				r = mid;
			}
			else if (cd[mid] < target) {
				l = mid;
			}
		}
		if (cd[r] == target) {
			small = r;
		}
		else {
			continue;
		}
		l = 0, r = n * n;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			if (cd[mid] > target) {
				r = mid;
			}
			else if (cd[mid] <= target) {
				l = mid;
			}
		}
		large = l;
		ans += large - small + 1;
	}
	cout << ans << '\n';
}