# include <iostream>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int ans = 0;
	int n;	cin >> n;
	while (n--){
		char x;	cin >> x;
		if (x == 'o'){
			++ans;
		}
		else {
			ans += 2;
		}
	}

	cout << ans;
}