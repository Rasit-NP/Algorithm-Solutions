# include <iostream>
using namespace std;

void print(int x){
	int a = x;
	int cnt = 0;
	while (a){
		if ((a%10) && (a%10)%3 == 0){
			++cnt;
		}
		a /= 10;
	}

	if (cnt == 0){
		cout << x;
	}
	else {
		while (cnt--){
			cout << '-';
		}
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int n;	cin >> n;
	for (int i=1; i<=n; i++){
		print(i);
		cout << " \n"[i==n];
	}
}