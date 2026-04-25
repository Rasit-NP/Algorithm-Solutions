# include <iostream>
# include <string>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int n;	cin >> n;
	cin.ignore();
	string sentence;
	while (n--){
		getline(cin, sentence);
		if (sentence.back() != '.'){
			sentence.push_back('.');
		}
		cout << sentence << '\n';
	}
}