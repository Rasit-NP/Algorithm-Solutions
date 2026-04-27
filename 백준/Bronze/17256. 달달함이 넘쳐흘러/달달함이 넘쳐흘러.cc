# include <iostream>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int ax, ay, az;		cin >> ax >> ay >> az;
	int cx, cy, cz;		cin >> cx >> cy >> cz;

	cout << cx-az << ' ' << cy/ay << ' ' << cz-ax;
}