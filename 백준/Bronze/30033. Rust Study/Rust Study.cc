# include <iostream>
# include <vector>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int n;	cin >> n;
	int ans = 0;
	vector<int> a(n, 0);

	for (int i=0; i<n; i++){
		cin >> a[i];
	}

	for (int i=0; i<n; i++){
		int x;	cin >> x;
		if (x >= a[i])
			++ans;
	}
	
	cout << ans;
}