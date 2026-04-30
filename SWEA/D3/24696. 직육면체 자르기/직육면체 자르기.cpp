# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;

    while (t--){
        int a, b, c;    cin >> a >> b >> c;
    
        if (a&b&c&1){
            cout << "2\n";
        }
        else {
            cout << "1\n";
        }
    }
}