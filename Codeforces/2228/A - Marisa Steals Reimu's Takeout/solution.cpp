# include <iostream>
# include <algorithm>
using namespace std;
 
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
 
	int t;	cin >> t;
	while (t--){
		int cnt[3] = {0, 0, 0};
		int n;	cin >> n;
		for (int i=0; i<n; i++){
			int x;	cin >> x;
			++cnt[x];
		}
		int c = min(cnt[1], cnt[2]);
		int ans = cnt[0] + c + (cnt[1] - c)/3 + (cnt[2] - c)/3;
		cout << ans << '\n';
	}
}