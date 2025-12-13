# include <iostream>
using namespace std;

int main(void){
	int w, h;
	cin >> w >> h;
	float ans = (float)w*h / 2;
	cout << fixed;
	cout.precision(1);
	cout << ans;
}