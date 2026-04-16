# include <iostream>
typedef long long llong;
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;
    while (t--){
        llong lt, wt, le, we;   cin >> lt >> wt >> le >> we;
        llong at = lt*wt, ae = le*we;
    
        if (at > ae){
            cout << "TelecomParisTech";
        }
        else if (at < ae){
            cout << "Eurecom";
        }
        else {
            cout << "Tie";
        }
        cout << '\n';
    }
    
}