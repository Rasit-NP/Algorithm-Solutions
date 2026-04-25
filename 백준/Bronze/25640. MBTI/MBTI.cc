# include <iostream>
# include <string>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	string my;	cin >> my;
	int n;	cin >> n;
	int res = 0;
	while(n--){
		string f;	cin >> f;
		if (my == f)
			++res;
	}
	cout << res;
}