# include <iostream>
# include <vector>
# include <algorithm>
# include <string>
using namespace std;

int timetrans(string time) {
	return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

int main(void) {
	string res[7] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
	string start1, start2, period1, period2;
	cin >> start1 >> start2;
	cin >> period1 >> period2;
	vector<int> times = { timetrans(start1) , timetrans(start2) };
	vector<int> periods = { timetrans(period1), timetrans(period2) };
	vector<bool> diff(1440, false);
	bool ans = true;
	while (times[0] != times[1]) {
		while (times[0] < times[1]) {
			times[0] += periods[0];
		}
		while (times[1] + periods[1] <= times[0]) {
			times[1] += periods[1];
		}
		if (times[0] >= 10080 && times[1] >= 10080) {
			times[0] %= 10080;
			times[1] %= 10080;
		}
		if (times[0] - times[1] >= 10080) {
			times[0] -= 10080;
			continue;
		}
		if (times[0] == times[1]) {
			break;
		}
		else if (diff[times[0] - times[1]]) {
			ans = false;
			break;
		}
		else {
			diff[times[0] - times[1]] = true;
		}
		times[1] += periods[1];
	}
	if (ans) {
		cout << res[times[0] / 1440] << '\n';
		int time = times[0] % 1440;
		int h = time / 60; int m = time % 60;
		if (h < 10)	cout << '0';
		cout << h;
		cout << ':';
		if (m < 10)	cout << '0';
		cout << m;
	}
	else {
		cout << "Never\n";
	}
}