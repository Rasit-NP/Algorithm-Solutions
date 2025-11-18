# include <iostream>
# include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, i = 0;
	cin >> n;
	vector<int> count(10001);
	for (; i < n; i++) {
		int x;
		cin >> x;
		count[x]++;
	}
	for (i = 1; i <= 10000; i++) {
		for (int j = 0; j < count[i]; j++) {
			cout << i << '\n';
		}
	}
}