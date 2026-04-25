# include <iostream>
# include <algorithm>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int n;	cin >> n;
	int d = 0, p = 0;

	while (n--){
		char x;	cin >> x;
		if (x == 'D'){
			++d;
		}
		else {
			++p;
		}
		if (abs(d-p) >= 2)
			break;
	}

	cout << d << ":" << p;
}