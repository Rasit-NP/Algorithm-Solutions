# include <iostream>
# include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    while(n--){
        string crypto;  cin >> crypto;
        if (crypto.length()>= 6 && crypto.length() <= 9)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}