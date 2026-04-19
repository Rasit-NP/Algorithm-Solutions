# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int T;  cin >> T;
    while (T--){
        int t;  cin >> t;
        if (t%25 < 17){
            cout << "ONLINE\n";
        }
        else {
            cout << "OFFLINE\n";
        }
    }
}