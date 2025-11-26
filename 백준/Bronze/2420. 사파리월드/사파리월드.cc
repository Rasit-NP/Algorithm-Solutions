# include <iostream>
using namespace std;

int main(void) {
	long long n, m;
	cin >> n >> m;
	if (n - m < 0) {
		cout << m - n;
	}
	else {
		cout << n - m;
	}
}