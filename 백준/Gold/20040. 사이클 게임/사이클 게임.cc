# include <iostream>
# include <queue>
# include <vector>
# include <algorithm>
using namespace std;

vector<int> parents;

int find(int x) {
	int node = x;
	while (parents[node] != node) {
		parents[node] = parents[parents[node]];
		node = parents[node];
	}
	parents[x] = node;
	return parents[node];
}

int main(void) {
	int n, m, ans = 0;
	cin >> n >> m;
	parents.assign(n, 0);
	for (int i = 0; i < n; i++) {
		parents[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b)  swap(a, b);
		int ra = find(a), rb = find(b);
		int r1 = max(ra, rb), r2 = min(ra, rb);
		if (r1 != r2) {
			parents[r1] = r2;
		}
		else if (r1 == r2 && !ans) {
			ans = i;
		}
	}
	cout << ans << '\n';
}