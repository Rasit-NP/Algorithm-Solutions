# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;
    while (t--){
        int n;  cin >> n;

        if ((n+1)%(n%100)){
            cout << "Bye";
        }
        else {
            cout << "Good";
        }
        cout << "\n";
    }
}