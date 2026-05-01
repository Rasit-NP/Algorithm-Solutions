# include <iostream>
# include <algorithm>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    
    int t;	cin >> t;
    while(t--){
    	int x, y, n;	cin >> x >> y >> n;
        int cnt = 0;
        while(x <= n && y<=n){
        	if (x<y){
            	x += y;
            }
            else {
            	y += x;
            }
            ++cnt;
        }
		cout << cnt << '\n';
    }
}