# include <iostream>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	char letter;
	while (cin >> letter){
		if (letter >= 'a'){
			letter -= 32;
		}
		else {
			letter += 32;
		}
		cout << letter;
	}
}