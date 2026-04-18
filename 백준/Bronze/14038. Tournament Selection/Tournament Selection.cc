# include <iostream>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int cnt = 0;
	char let;

	for (int i=0; i<6; i++){
		cin >> let;
		cnt += (let == 'W');
	}

	if (cnt > 4){
		cout << 1;
	}
	else if (cnt > 2){
		cout << 2;
	}
	else if (cnt > 0){
		cout << 3;
	}
	else {
		cout << -1;
	}
}