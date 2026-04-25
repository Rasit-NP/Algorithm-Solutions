# include <iostream>
# include <unordered_set>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	char x;
	int cnt = 0;
	unordered_set<char> sets = {'a', 'e', 'i', 'o', 'u'};
	while (cin >> x){
		if (sets.find(x) != sets.end()){
			++cnt;
		}
	}
	cout << cnt;
}