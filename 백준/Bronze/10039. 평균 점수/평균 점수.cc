# include <iostream>
# include <algorithm>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int sum = 0;
	for (int i=0; i<5; i++){
		int score;	cin >> score;

		sum += max(score, 40);
	}

	cout << sum/5;
}