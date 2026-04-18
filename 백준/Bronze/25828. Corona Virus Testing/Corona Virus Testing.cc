# include <iostream>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int g, p, t;	cin >> g >> p >> t;
	int origin = g*p;
	int cmp = g + p*t;

	if (origin < cmp){
		cout << 1;
	}
	else if (cmp < origin){
		cout << 2;
	}
	else {
		cout << 0;
	}
}