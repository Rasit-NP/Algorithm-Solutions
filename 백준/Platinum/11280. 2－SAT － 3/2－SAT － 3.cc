# include <iostream>
# include <queue>
# include <vector>
# include <algorithm>
# include <cmath>
using namespace std;

int node_cnt = 0;
vector<vector<int>> edges;
vector<int> ids;
vector<int> low;
vector<bool> on_stack;
deque<int> stack;
vector<vector<int>> SCCs;

void dfs(int x) {
	ids[x] = ++node_cnt;
	low[x] = ids[x];
	on_stack[x] = true;
	stack.push_back(x);

	for (int nx : edges[x]) {
		if (!ids[nx]) {
			dfs(nx);
			low[x] = low[x] < low[nx] ? low[x] : low[nx];
		}
		else if (on_stack[nx]) {
			low[x] = low[x] < ids[nx] ? low[x] : ids[nx];
		}
	}
	if (low[x] == ids[x]) {
		vector<int>* scc = new vector<int>();
		while (stack.size()) {
			int node = stack.back();
			stack.pop_back();
			(*scc).push_back(node);
			on_stack[node] = false;
			if (node == x)	break;
		}
		SCCs.push_back(*scc);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	edges.assign(2 * n, vector<int>(0));
	ids.assign(2 * n, 0);
	low.assign(2 * n, 0);
	on_stack.assign(2 * n, false);

	for (int cnt = 0; cnt < m; cnt++) {
		int i, j;
		cin >> i >> j;
		if (i < 0)
			i = abs(i) + n;
		if (j < 0)
			j = abs(j) + n;
		i--; j--;
		edges[(i + n) % (2 * n)].push_back(j);
		edges[(j + n) % (2 * n)].push_back(i);
	}

	for (int i = 0; i < 2 * n; i++) {
		if (!ids[i]) {
			dfs(i);
		}
	}

	int ans = 1;
	for (vector<int> scc : SCCs) {
		vector<bool> check(n, false);
		for (int x : scc) {
			if (check[x%n]) {
				ans = 0;
			}
			check[x%n] = true;
		}
	}
	cout << ans << '\n';
}