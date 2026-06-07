# include <iostream>
typedef long long llong;
using namespace std;
 
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
 
	int t;	cin >> t;
	while (t--){
		llong n;	cin >> n;
		int loss = n % 12;
 
		if (loss != 10){
			cout << loss << ' ' << n - loss;
		}
		else {
			if (n == 10){
				cout << -1;
			}
			else {
				cout << 22 << ' ' << n - 22;
			}
		}
		cout << '\n';
	}
}