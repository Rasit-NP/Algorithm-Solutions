# include <iostream>
# include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int cnt = 0;
	while (true) {
		string word;
		cin >> word;
		if (cin.fail())
			break;
		else
			cnt++;
	}
	cout << cnt;
}