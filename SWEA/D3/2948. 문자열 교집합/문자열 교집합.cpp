# include <iostream>
# include <queue>
# include <vector>
# include <unordered_map>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 1; t<=T; t++){
		int n, m;
		cin >> n >> m;
		int cnt=0;
		unordered_map<string, bool> table;
		string name;
		for (int i=0; i<n; i++){
			cin >> name;
			table[name] = true;
		}
		for (int i=0; i<m; i++){
			cin >> name;
			if (table[name]){
				cnt++;
			}
		}
		cout << "#" << t << ' ';
		cout << cnt << endl;
	}
}