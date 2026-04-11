# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
# include <climits>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int n, m, x, y;		cin >> n >> m >> x >> y;
	vector<vector<pair<int, int>>> edges(n, vector<pair<int, int>>(0));
	vector<int> distFrom0(n, INT_MAX);
	for (int i=0; i<m; i++){
		int a, b, c;	cin >> a >> b >> c;
		edges[a].push_back({b, c});
		edges[b].push_back({a, c});
	}

	priority_queue<pair<int, int>> pq;
	pq.push({0, y});
	distFrom0[y] = 0;

	while (pq.size()){
		int dist = -pq.top().first, now = pq.top().second;	pq.pop();

		if (dist > distFrom0[now]){
			continue;
		}
		for (const auto& [nx, c] : edges[now]){
			if (dist + c < distFrom0[nx]){
				distFrom0[nx] = dist + c;
				pq.push({-distFrom0[nx], nx});
			}
		}
	}

	sort(distFrom0.begin(), distFrom0.end());

	int ans = 1;
	int todayWork = 0;
	for (int i=0; i<n;){
		int dist = distFrom0[i];
		if (todayWork + 2*dist <= x){
			todayWork += 2*dist;
			i++;
		}
		else if (todayWork == 0){
			ans = -1;
			break;
		}
		else {
			ans += 1;
			todayWork = 0;
		}
	}

	cout << ans;
}