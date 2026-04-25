# include <iostream>
# include <string>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int ans = 0;
	int n;	cin >> n;
	string s, t;	cin >> s >> t;
	for (int i=0; i<n; i++){
		if (s[i] != t[i]){
			++ans;
		}
	}

	cout << ans;
}