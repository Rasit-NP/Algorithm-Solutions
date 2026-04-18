# include <iostream>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int x, y, z;	cin >> x >> y >> z;

	if (x+y <= z){
		cout << 1;
	}
	else {
		cout << 0;
	}
}