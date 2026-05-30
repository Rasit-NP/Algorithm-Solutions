# include <iostream>
# include <map>
# include <algorithm>
using namespace std;
 
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
 
	int t;	cin >> t;
	while (t--){
		int n;	cin >> n;
		int l = 1000000001, r = 0;
		map<int, int> table;
		for (int i=0; i<n; i++){
			int a;	cin >> a;
			++table[a];
			l = min(l, a);
			r = max(r, a);
		}
		
		int res = 1001;
		int bef = 0, aft = n;
 
		for (const auto& [a, cnt] : table){
			aft -= cnt;
			int local = 0;
			if (a == l || a == r){
				local = n - cnt;
			}
			else {
				local = max(bef, aft);
			}
 
			bef += cnt;
 
			res = min(res, local);
		}
 
		cout << res << '\n';
	}
}