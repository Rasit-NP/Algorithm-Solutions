# include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int l, i=0;
	long long hash = 0;
	cin >> l;
	for (; i < l; i++) {
		static long long coef = 1;
		char letter;
		cin >> letter;
		long long num = letter - 'a' + 1;
		hash += num * coef;
		hash %= 1234567891;
		coef *= 31;
		coef %= 1234567891;
	}
	cout << hash << '\n';
}