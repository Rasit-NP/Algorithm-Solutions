# include <iostream>
# include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;
	int big = max(a, b), small = min(a, b);
	while (small != 0) {
		int temp = big % small;
		big = small;
		small = temp;
	}
	int num1 = big;
	int num2 = (a*b)/num1;
	cout << num1 << '\n' << num2 << '\n';
}