# include <iostream>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int cut[] = {0, 4500, 1000, 25};
	int t;	cin >> t;
	for (int tc=1; tc<=t; tc++){
		int n;	cin >> n;
		int round = 1;
		cout << "Case #" << tc;
		for (; round < 4; round++){
			if (n > cut[round]){
				cout << ": Round " << round << '\n';
				break;
			}
		}
		if (round == 4){
			cout << ": World Finals\n";
		}
	}
}