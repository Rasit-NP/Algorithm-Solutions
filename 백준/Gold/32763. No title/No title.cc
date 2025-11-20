# include <iostream>
# include <algorithm>
# include <vector>
# include <queue>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, i = 1, first = -1;
	char pm;
	cin >> n;
	vector<int> cmp(n, 0);
	cmp[0] = 1;
	for (; i < n; i++) {
		cout << "? 1 * " << i + 1 << '\n'; cout << flush;
		cin >> pm;
		if (pm == '+') {
			cmp[i] = 1;
			if (first == -1) {
				cout << "? 1 + " << i + 1 << '\n'; cout << flush;
				cin >> pm;
				if (pm == '+')
					first = 1;
				else
					first = 0;
			}
		}
		else {
			cmp[i] = 0;
		}
	}
	if (first == -1) {
		cout << "? 2 + 3" << '\n'; cout << flush;
		cin >> pm;
		if (pm == '+')
			first = 0;
		else
			first = 1;
	}
	char signs[2] = { '+', '-' };
	cout << '!';
	for (i = 0; i < n; i++) {
		cout << " " << signs[first^cmp[i]];
	}
	cout << '\n'; cout << flush;
	return 0;
}