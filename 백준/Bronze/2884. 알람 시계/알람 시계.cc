# include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio;
	cin.tie(NULL);

	int h, m;
	cin >> h >> m;
	int time = h * 60 + m - 45;
	time = time >= 0 ? time : time + 24 * 60;
	cout << time / 60 << ' ' << time % 60;
}