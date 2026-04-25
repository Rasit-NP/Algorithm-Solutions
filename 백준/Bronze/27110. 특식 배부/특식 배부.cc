# include <iostream>
# include <algorithm>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int n;	cin >> n;
	int a, b, c;	cin >> a >> b >> c;

	cout << min(a, n) + min(b, n) + min(c, n);
}