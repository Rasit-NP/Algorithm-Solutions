# include <iostream>
# include <queue>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, tc=1;
	cin >> t;
	while (tc++ <= t) {
		int n, m, cnt=0, ans;
		cin >> n >> m;
		queue<pair<int, int>> printq;
		priority_queue<int> heap;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			printq.push(make_pair(i, x));
			heap.push(x);
		}
		while (heap.size()) {
			int target = heap.top();
			heap.pop();
			while (printq.front().second != target) {
				pair<int, int> now_pair = printq.front();
				printq.pop();
				printq.push(now_pair);
			}
			pair<int, int> now_pair = printq.front();
			printq.pop();
			cnt += 1;
			if (now_pair.first == m) {
				ans = cnt;
				break;
			}
		}
		cout << ans << '\n';
	}
}