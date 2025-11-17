# include <iostream>
# include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio;
	cin.tie(NULL);

	int a, b, c, i=0;
	cin >> a >> b >> c;
	int mult = a * b*c;
	vector<int> used(10);
	while (mult != 0) {
		used[mult % 10]++;
		mult /= 10;
	}
	for (; i < 10; i++) {
		cout << used[i] << '\n';
	}
}