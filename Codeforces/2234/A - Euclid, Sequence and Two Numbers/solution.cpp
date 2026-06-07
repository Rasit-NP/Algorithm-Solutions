# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
 
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
 
	int t;	cin >> t;
	while (t--){
		int n;	cin >> n;
		vector<int> nums;
		for (int i=0; i<n; i++){
			int x;	cin >> x;
			nums.emplace_back(x);
		}
 
		sort(nums.begin(), nums.end());
		bool ans = true;
		for (int i=n-1; i>1; i--){
			if (nums[i-2] == nums[i] % nums[i-1]){
				continue;
			}
			else {
				ans = false;
			}
		}
 
		if (ans){
			cout << nums[n-1] << ' ' << nums[n-2];
		}
		else {
			cout << -1;
		}
		cout << '\n';
	}
}