# include <iostream>
# include <string>
using namespace std;
 
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
 
	int t;	cin >> t;
 
	while (t--){
		int n;	cin >> n;
		string a, b;	cin >> a >> b;
 
		bool ans = true;
		int sameLeft = 0;
		int diff = 0;
 
		for (int i=0; i<n; i++){
			char ai = a[i], bi = b[i];
 
			if (ai == '(' && bi == '('){
				++sameLeft;
			}
			else if (ai != bi){
				diff ^= 1;
			}
			else{
				--sameLeft;
			}
 
			if (sameLeft < 0 || (!sameLeft && diff)){
				ans = false;
			}
		}
 
		if (sameLeft || diff){
			ans = false;
		}
 
		cout << (ans ? "YES" : "NO") << '\n';
	}
}