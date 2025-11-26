# include <iostream>
using namespace std;

int main(void) {
	long long n;
	cin >> n;

	long long ans = 0, bias = 1;
	for (; n > 0; n = n >> 1, bias *= 3) {
		if (n & 1) {
			ans += bias;
		}
	}
	cout << ans << '\n';
}