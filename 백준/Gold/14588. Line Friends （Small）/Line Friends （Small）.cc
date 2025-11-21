# include <iostream>
# include <algorithm>
# include <vector>
# include <queue>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, i, j;
	cin >> n;
	vector<vector<int>> edges(n+1, vector<int>(0));
	vector<pair<int, int>> lines(n + 1);
	for (i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		lines[i+1] = make_pair(l, r);
	}
	for (i = 1; i < n; i++) {
		for (j = i+1; j < n+1; j++) {
			if (lines[i].second < lines[j].first || lines[i].first > lines[j].second) {
				continue;
			}
			else {
				edges[i].push_back(j);
				edges[j].push_back(i);
			}
		}
	}
	int Q;
	cin >> Q;
	for (int query = 0; query < Q; query++) {
		vector<int> visited(n + 1, 0);
		queue<int> q;
		int a, b;
		cin >> a >> b;
		visited[a] = 1;
		q.push(a);
		int ans = -1;
		while (q.size()) {
			int x = q.front();
			q.pop();
			if (x == b) {
				ans = visited[x] - 1;
				break;
			}
			int length = edges[x].size();
			for (int i = 0; i < length; i++) {
				int nx = edges[x][i];
				if (visited[nx] == 0) {
					visited[nx] = visited[x] + 1;
					q.push(nx);
				}
			}
		}
		cout << ans << '\n';
	}
}