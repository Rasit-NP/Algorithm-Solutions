# include <iostream>
# include <string>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	string x;

	for (int i = 0; i < 2 * (n - 1) - 1; i++) {
		getline(cin, x);
	}
	cout << 2 * (n - 1) << ' ' << 2 * (n - 1) - 1;
}