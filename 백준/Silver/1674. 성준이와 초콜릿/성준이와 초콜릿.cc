# include <iostream>
# include <string>
# include <vector>
# include <queue>
# include <algorithm>
# include <cmath>
# include <iomanip>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string query;
	int t, time; double n, time_limit;
	vector<double> gauge_int(1000005, 0);
	vector<int> gauge_12(1000005, 0);
	vector<int> gauge_79(1000005, 0);
	priority_queue<int> heap;
	while (cin >> query) {
		if (query == "Query") {
			cin >> t;
			heap.push(-t);
		}
		else if (query == "Chocolate") {
			cin >> t >> n;
			time_limit = 96 * n;
			for (time = t; time-t < time_limit; time++) {
				if (time > 1000000)	break;
				gauge_int[time] += 8 * n;
				gauge_12[time] += time - t;
			}
		}
		else {
			cin >> t >> n;
			time_limit = 158 * n;
			for (time = t; (time-t)*(time-t) < time_limit; time++) {
				if (time > 1000000)	break;
				gauge_int[time] += 2 * n;
				gauge_79[time] += (time - t)*(time - t);
			}
		}
	}
	while (heap.size()) {
		time = -heap.top();	heap.pop();
		long double range = (long double)gauge_int[time] - (long double)gauge_12[time] / 12 - (long double)gauge_79[time] / 79;
		range = floor(range*10.0L + 0.5L) / 10.0L;

		if (range < 1.0L) {
			range = 1.0L;
		}
		cout << time << ' ';
		cout << fixed << setprecision(1) << range << endl;
	}
}