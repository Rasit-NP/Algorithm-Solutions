# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main(void) {
	int n, m;	cin >> n >> m;
	vector<int> nums;
	for (int i = 0; i < m; i++) {
		nums.assign(n, 0);
		long long ans = 1;
		int minus = 0;
		int zero = 0;
		int largest_minus = -3;
		for (int j = 0; j < n; j++) {
			cin >> nums[j];
			if (nums[j] == 0) {
				zero++;
			}
			else if (nums[j] < 0) {
				minus++;
				largest_minus = max(largest_minus, nums[j]);
			}
		}
		if (n == zero) {
			cout << 0 << endl;
			continue;
		}
		else if (n == 1) {
			cout << nums[0] << endl;
			continue;
		}
		for (int j = 0; j < n; j++) {
			if (nums[j] == 0)	continue;
			ans *= nums[j];
		}
		if (minus == 1 && minus+zero == n) {
			cout << 0 << endl;
		}
		else if (minus & 1) {
			cout << ans / largest_minus << endl;
		}
		else {
			cout << ans << endl;
		}
	}
}