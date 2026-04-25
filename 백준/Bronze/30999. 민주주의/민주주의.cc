# include <iostream>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int n, m;	cin >> n >> m;
	int ans = 0;

	while (n--){
		int cnt = 0;
		for (int i=0; i<m; i++){
			char x;	cin >> x;
			if (x == 'O')
				++cnt;
		}
		if (2*cnt > m)
			++ans;
	}

	cout << ans;
}