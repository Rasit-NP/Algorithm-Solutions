# include <iostream>
# include <vector>
# include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int n, q;	cin >> n >> q;
	string num;	cin >> num;
	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++) {
		nums[i] = stoi(num.substr(i, 1));
	}
	for (int i = 0; i < q; i++) {
		int order;	cin >> order;
		if (order == 1) {
			int i;	cin >> i;
			nums[i - 1] = !nums[i - 1];
		}
		else if (order == 2) {
			int x, y;	cin >> x >> y;
			if (y - x + 1 >= 4) {
				cout << "YES\n";
			}
			else {
				if (y - x + 1 < 2) {
					cout << "NO\n";
					continue;
				}
				else if (y - x + 1 == 2 && nums[x-1]+nums[x] == 1) {
					cout << "NO\n";
					continue;
				}
				else if (y - x + 1 == 3 && nums[x - 1] + nums[x] == 1 && nums[x] + nums[x + 1] == 1) {
					cout << "NO\n";
					continue;
				}
				cout << "YES\n";
			}
		}
	}
}