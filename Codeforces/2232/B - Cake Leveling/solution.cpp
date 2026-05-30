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
		vector<int> a(n, 0);
 
		for (int i=0; i<n; i++){
			int x;	cin >> x;
			a[i] = x;
		}
 
		int latest = a[0];
		long long sum = a[0];
		cout << latest;
		for (long long i=1; i<n; i++){
			sum += a[i];
			int h = sum / (i+1);
			latest = min(latest, h);
			cout << ' ' << latest;
		}
		cout << '\n';
	}
}