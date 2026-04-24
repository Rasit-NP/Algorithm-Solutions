# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;
    while (t--){
        int n;  cin >> n;

        for (int i=0; i<(n/5); i++){
            cout << "++++ ";
        }
        for (int i=0; i<(n%5); i++){
            cout << "|";
        }
        cout << endl;
    }
}