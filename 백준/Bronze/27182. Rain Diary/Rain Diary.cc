# include <iostream>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int n, m;	cin >> n >> m;
	if (n > 7){
		cout << n-7;
	}
	else {
		cout << m+7;
	}
}