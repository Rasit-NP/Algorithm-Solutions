# include <iostream>
# include <vector>
using namespace std;

int main(void) {
	int n;
	vector<bool> students(31, false);
	for (int i = 0; i < 28; i++) {
		cin >> n;
		students[n] = true;
	}
	for (int i = 1; i < 31; i++) {
		if (!students[i])
			cout << i << '\n';
	}
}