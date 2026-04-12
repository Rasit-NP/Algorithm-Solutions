# include <iostream>
using namespace std;

int main(void){
	int t;	cin >> t;
    int tc=0;
    while (++tc<=t){
    	int ans = 0;
        for (int i=0; i<10; i++){
        	int x;	cin >> x;
            if (x&1)
                ans += x;
        }
       	cout << "#" << tc << " " << ans << '\n';
    }
}