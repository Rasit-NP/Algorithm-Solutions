# include <iostream>
using namespace std;

int main(void){
	int t;	cin >> t;
    for (int tc=1; tc<=t; tc++){
    	int a, b;	cin >> a >> b;
        cout << "#" << tc;
        if (a<b){
        	cout << ' ' << "<\n";
        }
        else if (a>b){
        	cout << ' ' << ">\n";
        }
        else {
            cout << ' ' << "=\n";
        }
    }
}