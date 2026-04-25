# include <iostream>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int n;	cin >> n;
	int now = 0, before;
	while (n--){
		if (now){
			before = now;
		}
		cin >> now;
	}
	cout << 2*now - before;
}