# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

long long LCM(long long x, int y) {
	long long a, b;
	if (x >= y) {
		a = x;
		b = y;
	}
	else {
		a = y;
		b = x;
	}
	while (a%b) {
		long long loss = a % b;
		a = b, b = loss;
	}
	long long gcd = b;
	return (x/gcd)*y;
}

int main(void) {
	int k, n;
	cin >> k >> n;
	vector<int> nums(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	long long ans = 1;

	for (int num : nums) {
		ans = LCM(ans, num);
	}
	cout << ans - k << '\n';
}