# include <iostream>
# include <vector>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int n;	cin >> n;
	long long res = 0;
	int state = 0;
	for (int i=0; i<n; i++){
		int x;	cin >> x;
		if (x == 0){
			state--;
		}
		else {
			state++;
		}
		res += state;
	}
	cout << res;
}